#pragma once
#include <iostream>

#define INIT_CAPACITY 3

template<typename T>
class dynamic_array
{
private:
	size_t m_size = 0;
	size_t m_capacity = INIT_CAPACITY;
	T* m_data = nullptr;
	int m_sizeIncrement = 1;

public:
	dynamic_array()
	{
		ReAlloc(m_capacity);
	}
	~dynamic_array()
	{
		Clear();
		operator delete(m_data, m_capacity * sizeof(T));
	}

	T& PushBack(const T& data)
	{
		if (m_size >= m_capacity)
		{
			std::cout << "Reallocating new array\n";
			ReAlloc(m_capacity + m_capacity/2 );
		}
		m_data[m_size] = data;
		
		return m_data[m_size++];
	}

	T& PushBack(T&& data)
	{
		if (m_size >= m_capacity)
		{
			std::cout << "Reallocating new array\n";
			ReAlloc(m_capacity + m_capacity / 2);
		}
		m_data[m_size++] = std::move(data);

		return m_data[m_size++];
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_size >= m_capacity)
		{
			std::cout << "Reallocating new array\n";
			ReAlloc(m_capacity + m_capacity / 2);
		}

		new(&m_data[m_size]) T(std::forward<Args>(args)...);
		return m_data[m_size++];
	}

	T& PopBack()
	{
		if (m_size > 0)
		{
			T res;
			res = m_data[--m_size];
			m_data[m_size].~T();
			return res;
		}
	}

	void Clear()
	{
		for (size_t i = 0; i < m_size; i++)
			m_data[i].~T();

		m_size = 0;
	}

	const size_t GetSize() const
	{
		return m_size;
	}

	const T& operator[](size_t index) const
	{
		if (index >= m_size);
		return m_data[index];
	}

	T& operator[](size_t index)
	{
		if (index >= m_size);
		return m_data[index];
	}

private:
	void ReAlloc(size_t newCapacity)
	{
		T* newData = static_cast<T*>(operator new(newCapacity * sizeof(T)));
		
		if (newCapacity < m_size)
		{
			m_size = newCapacity;
		}

		for (size_t i = 0; i < m_size; i++)
			newData[i] = std::move(m_data[i]);

		for (size_t i = 0; i < m_size; i++)
			m_data[i].~T();

		operator delete(m_data, m_capacity * sizeof(T));
		m_data = newData;
		m_capacity = newCapacity;
	}
};