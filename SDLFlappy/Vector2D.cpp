#include "Vector2D.h"

Vector2D::Vector2D() {
	x = 0.0f;
	y = 0.0f;
}
Vector2D::Vector2D(float x, float y) {
	this->x = x;
	this->y = y;
}
Vector2D& Vector2D::Add(const Vector2D& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
	// TODO: insert return statement here
}

Vector2D& Vector2D::Subtract(const Vector2D& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
	// TODO: insert return statement here
}

Vector2D& Vector2D::Multiply(const Vector2D& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
	// TODO: insert return statement here
}

Vector2D& Vector2D::Divide(const Vector2D& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;
	return *this;
	// TODO: insert return statement here
}

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
	return this->Add(vec);
	// TODO: insert return statement here
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
	return this->Subtract(vec);
	// TODO: insert return statement here
}

Vector2D& Vector2D::operator*=(const Vector2D& vec)
{
	return this->Multiply(vec);
	// TODO: insert return statement here
}

Vector2D& Vector2D::operator/=(const Vector2D& vec)
{
	return this->Subtract(vec);
	// TODO: insert return statement here
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
	return v1.Add(v2);
	// TODO: insert return statement here
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
	return v1.Subtract(v2);
	;	// TODO: insert return statement here
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
	return v1.Multiply(v2);
	// TODO: insert return statement here
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
	return v1.Divide(v2);
	// TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec)
{
	stream << "(" << vec.x << "," << vec.y << ")";
	return stream;
	// TODO: insert return statement here
}


