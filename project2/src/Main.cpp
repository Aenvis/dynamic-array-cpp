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
std::ostream& operator<<(std::ostream& stream, const Vector3& v)
{
	stream << "(" << v.x << " " << v.y << " " << v.z << ")";
	return stream;
}

int main()
{
	dynamic_array<Vector3> v;
	
	v.EmplaceBack(1, 2, 3);
	v.EmplaceBack(3);
	v.EmplaceBack(4, 2, 1);
	v.EmplaceBack();

	for (dynamic_array<Vector3>::Iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cin.get();
}