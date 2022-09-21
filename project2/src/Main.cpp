#include <iostream>

namespace vector
{
#define MAX_INIT_SIZE 1000
	template<typename T>
	class dynamic_array
	{
	private:
		uint64_t m_size = -1;
		T m_arr[MAX_INIT_SIZE]{};
		int m_sizeIncrement=0;
	public:
		dynamic_array()
			: m_size(0)
		{
			m_arr[m_size] = 0;
		}

		void emplace_back(T data)
		{
			if (m_size < MAX_INIT_SIZE - 1)
				m_arr[m_size++] = data;
			else
			{
				
			}
		}

		T operator[](int index)
		{
			return m_arr[index];
		}
	};
}
int main()
{
	vector::dynamic_array<int> years;
	years.emplace_back(1915);
	std::cout << years[0];
	std::cin.get();
}