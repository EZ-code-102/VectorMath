#pragma once


class Vec3 {
public:
	//Default constructor
	Vec3();

	//Primary constructor
	Vec3(float const x, float const y, float const z);

	//Copy constructor
	Vec3(Vec3 const &vec);

	// AUX FUNCTIONS
	//Updates all members
	void UpdateAll();

	//Calculate its magnitude
	void CalcMagnitude();





//--- VARIABLES --------------
	//Direction
	float m_x, m_y, m_z;

	//Magnitude
	float m_mag;

private:
	
};

//---------- DEFAULT VECTORS ---------------
extern Vec3 ihat;
extern Vec3 jhat;
extern Vec3 khat;
//------------------------------------------



class TransformMatrix {
public:
	//Default constructor
	TransformMatrix();
	//Primary constructor
	TransformMatrix(float const _00, float const _01, float const _02, float const _10, float const _11, float const _12, float const _20, float const _21, float const _22);

	float m_values[3][3];

};






//------------ NAMESPACE VMATH -------------------
namespace vmath
{
	//Product of a scalar with a vec3
	Vec3 scalarProduct(Vec3 const &vec, float const scalar);

	//Sum of two Vec3 instances
	Vec3 vec3Sum(Vec3 const &lhs, Vec3 const &rhs);

	//Substraction ob two Vec3 instances
	Vec3 vec3Sub(Vec3 const &lhs, Vec3 const &rhs);

	//Comparison between Vec3 magnitudes
	Vec3 vec3Max(Vec3 const &lhs, Vec3 const &rhs);

	//Dot product of two Vec3 instances
	float vec3dotProduct(Vec3 const &lhs, Vec3 const &rhs);

	//Checks two vec3 for colineal
	bool vec3Colinear(Vec3 const &lhs, Vec3 const &rhs);

	//Gives the vecotr perpendicular two the two given
	Vec3 vec3VectorProduct(Vec3 const &lhs, Vec3 const &rhs);

	//Normalizes a vector so that its magnitude equals one
	Vec3 vec3Normalize(Vec3 const &vec);

	//Returns a vector that is midway from two vectors (linear interpolation)
	Vec3 vec3LERP(Vec3 const &lhs, Vec3 const &rhs, float const beta);
}
//----------------------------------------------------------------------------