#pragma once
#include <iostream>

#define INIT_CAPACITY 10

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
		delete[] m_data;
	}

	void PushBack(const T& data)
	{
		if (m_size >= m_capacity)
		{
			std::cout << "Reallocating new array\n";
			ReAlloc(m_capacity + m_capacity/2 );
		}
		m_data[m_size++] = data;
	}

	void EmplaceBack(T&& data)
	{
		if (m_size >= m_capacity)
		{
			std::cout << "Reallocating new array\n";
			ReAlloc(m_capacity + m_capacity / 2);
		}
		m_data[m_size++] = std::move(data);
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
		if (newCapacity < m_size)
		{
			m_size = newCapacity;
		}

		m_capacity = newCapacity;
		T* tempData = new T[m_capacity];
		for (size_t i = 0; i < m_size; i++)
			tempData[i] = m_data[i];

		delete[] m_data;
		m_data = tempData;
	}
};