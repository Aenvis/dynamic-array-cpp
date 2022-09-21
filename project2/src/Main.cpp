#include <iostream>

namespace vector
{
#define MAX_INIT_SIZE 1000
	class dynamic_array
	{
	private:
		uint64_t m_size = -1;
		uint64_t m_maxSize = MAX_INIT_SIZE;
		int* m_arr = new int[m_maxSize];
		int m_sizeIncrement=1;
	public:
		dynamic_array()
			: m_size(0)
		{
			m_arr[m_size] = 0;
		}
		~dynamic_array()
		{
			delete[] m_arr;
		}

		void emplace_back(int data)
		{
			if (m_size >= m_maxSize)
			{
				std::cout << "Allocating new array twice the size\n";
				m_sizeIncrement++;
				m_maxSize = m_sizeIncrement * MAX_INIT_SIZE;
				int* temp_arr = new int[m_maxSize];
				for (size_t i = 0; i < (m_sizeIncrement - 1) * MAX_INIT_SIZE; i++)
				{
					temp_arr[i] = m_arr[i];
				}
				m_arr = temp_arr;
				delete[] temp_arr;
			}
				m_arr[m_size++] = data;
		}

		int GetSize() const
		{
			return m_size;
		}

		int operator[](int index)
		{
			return m_arr[index];
		}
	};
}
int main()
{
	vector::dynamic_array years;
	for (size_t i = 0; i < 1002; i++)
	{
		years.emplace_back(i);
	}
		
	std::cout << years.GetSize();

	std::cin.get();
}