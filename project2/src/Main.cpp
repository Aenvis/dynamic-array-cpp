#include <iostream>
#include "dynamic_array.h"

class Vector3
{
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;

public:
	Vector3(){}

	Vector3(float x, float y, float z)
		: x(x), y(y), z(z){}

	Vector3(float scalar)
		: x(scalar), y(scalar), z(scalar){}

	Vector3(const Vector3& other)
		: x(other.x), y(other.y), z(other.z){}

	Vector3(Vector3&& other) noexcept
		: x(other.x), y(other.y), z(other.z){}

	~Vector3()
	{
		std::cout << "Destroyed\n";
	}

	Vector3& operator=(const Vector3& other)
	{
		std::cout << "Copied\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
	
	Vector3& operator=(Vector3&& other) noexcept
	{
		std::cout << "Moved\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
};

void PrintVector(const dynamic_array<Vector3>& array)
{
	for (size_t i = 0; i < array.GetSize(); i++)
	{
		std::cout << "(" << array[i].x << " " << array[i].y << " " << array[i].z << ")" << std::endl;
	}
}

int main()
{
	dynamic_array<Vector3> v;
	
	v.EmplaceBack(1, 2, 3);
	v.EmplaceBack(3);
	v.EmplaceBack();
	v.EmplaceBack();

	PrintVector(v);
		
	std::cin.get();
}