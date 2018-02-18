#include <vmath.h>
#include <cmath>

//---------- DEFAULT VECTORS -----------
Vec3 ihat(1.0, 0.0, 0.0);
Vec3 jhat(0.0, 1.0, 0.0);
Vec3 khat(0.0, 0.0, 1.0);
//--------------------------------------

//Default Constructor
Vec3::Vec3()
{
	//Sets direction to (1, 1, 1)
	m_x = 1.0;
	m_y = 1.0;
	m_z = 1.0;

	//Updates all members
	UpdateAll();
}

//Primary constructor
Vec3::Vec3(float const x, float const y, float const z)
{
	m_x = x;
	m_y = y;
	m_z = z;
	UpdateAll();
}

//Copy constructor
Vec3::Vec3(Vec3 const &vec)
{
	m_x = vec.m_x;
	m_y = vec.m_y;
	m_z = vec.m_z;
	UpdateAll();
}


//--------------- AUX FUNCTIONS ----------------------------

//Updates all members based on coordinates
void Vec3::UpdateAll()
{
	CalcMagnitude();
}

//Calculates the current magnitude of the vector
void Vec3::CalcMagnitude()
{
	float sum = 0.0f;
	sum += m_x * m_x;
	sum += m_y * m_y;
	sum += m_z * m_z;
	m_mag = sqrt(sum);
}





//------------ CLASS TRANSFORM MATRIX ----------------------------

//Default constructor
TransformMatrix::TransformMatrix()
{
	for (unsigned i = 0; i < 2; ++i) {
		for (unsigned j = 0; j < 2; ++j) {
			m_values[i][j] = 0.0f;
		}
	}
}

//Primary constructor
TransformMatrix::TransformMatrix(float const _00, float const _01, float const _02, float const _10, float const _11, float const _12, float const _20, float const _21, float const _22)
{
	m_values[0][0] = _00;
	m_values[0][1] = _01;
	m_values[0][2] = _02;
	m_values[1][0] = _10;
	m_values[1][1] = _11;
	m_values[1][2] = _12;
	m_values[2][0] = _20;
	m_values[2][1] = _21;
	m_values[2][2] = _22;
}


//----------------------------------------------------------------




//--------------- NAMESPACE VMATH ---------------------------

namespace vmath
{
	//Multiplies the vector with a scalar
	Vec3 scalarProduct(Vec3 const &vec, float const scalar)
	{
		Vec3 result;
		result.m_x = vec.m_x * scalar;
		result.m_y = vec.m_y * scalar;
		result.m_z = vec.m_z * scalar;
		result.UpdateAll();
		return result;
	}

	//Sum of two Vec3 instances
	Vec3 vec3Sum(Vec3 const &lhs, Vec3 const &rhs)
	{
		Vec3 sum;
		sum.m_x = lhs.m_x + rhs.m_x;
		sum.m_y = lhs.m_y + rhs.m_y;
		sum.m_z = lhs.m_z + rhs.m_z;
		sum.UpdateAll();
		return sum;
	}

	//Substraction of two Vec3 instances
	Vec3 vec3Sub(Vec3 const &lhs, Vec3 const &rhs)
	{
		Vec3 sub;
		sub.m_x = lhs.m_x - rhs.m_x;
		sub.m_y = lhs.m_y - rhs.m_y;
		sub.m_z = lhs.m_z - rhs.m_z;
		sub.UpdateAll();
		return sub;
	}

	//Comparison between Vec3 magnitudes
	Vec3 vec3Max(Vec3 const &lhs, Vec3 const &rhs)
	{
		return lhs.m_mag < rhs.m_mag ? rhs : lhs;
	}

	//Dot product of two Vec3 instances
	float vec3dotProduct(Vec3 const &lhs, Vec3 const &rhs)
	{
		float dot = 0.0;
		dot += lhs.m_x * rhs.m_x;
		dot += lhs.m_y * rhs.m_y;
		dot += lhs.m_z * rhs.m_z;
		return dot;
	}

	//Checks for two vec3 to be colinear
	bool vec3Colinear(Vec3 const &lhs, Vec3 const &rhs)
	{
		float dot = vmath::vec3dotProduct(lhs, rhs);
		float check = lhs.m_mag * rhs.m_mag;
		return dot == check ? true : false;
	}

	//Gives the vecotr perpendicular two the two given
	Vec3 vec3VectorProduct(Vec3 const &lhs, Vec3 const &rhs)
	{
		Vec3 vectorProduct;
		vectorProduct.m_x = (lhs.m_y * rhs.m_z) - (lhs.m_z * rhs.m_y);
		vectorProduct.m_y = (lhs.m_z * rhs.m_x) - (lhs.m_x * rhs.m_z);
		vectorProduct.m_z = (lhs.m_x * rhs.m_y) - (lhs.m_y * rhs.m_x);
		vectorProduct.UpdateAll();
		return vectorProduct;
	}

	//Normalizes a vector so that its magnitude equals one
	Vec3 vec3Normalize(Vec3 const &vec)
	{
		Vec3 normalized;
		float magInverse = 1.0f / vec.m_mag;
		normalized = vmath::scalarProduct(vec, magInverse);
		return normalized;
	}

	//Returns a vector that is midway from two vectors (linear interpolation)
	Vec3 vec3LERP(Vec3 const &lhs, Vec3 const &rhs, float const beta)
	{
		Vec3 lerp;
		Vec3 a;
		Vec3 b;
		a = vmath::scalarProduct(lhs, 1.0f - beta);
		b = vmath::scalarProduct(rhs, beta);
		lerp = vmath::vec3Sum(a, b);
		return lerp;
	}
}