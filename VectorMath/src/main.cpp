#include <vmath.h>
#include <iostream>

using std::cout;
using std::endl;


void PrintVec3(Vec3 const &vec)
{
	cout << "X value : " << vec.m_x << endl;
	cout << "Y value : " << vec.m_y << endl;
	cout << "Z value : " << vec.m_z << endl;
	cout << "Magnitude : " << vec.m_mag << endl;
	cout << endl;
}


int main(void)
{


	Vec3 a(2.0f, 1.0f, 0.0f);
	Vec3 b(2.0f, 3.0f, 0.0f);

	Vec3 c = vmath::vec3LERP(a, b, 0.1f);
	PrintVec3(a);
	PrintVec3(b);
	PrintVec3(c);

	system("PAUSE");
	return 0;
}