#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{
public:
	~Vector();
	Vector();
	Vector(const T capacity);
	Vector(const Vector& other);
	Vector(Vector&& other);
	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other);

	int getM_capacity() const;
	int getM_size() const;
	void push_back(T elem);
	void pop_back(T elem);
	void realloc();

	T& operator[](int pos);

private:
	int m_size;
	int m_capacity;
	T* m_ptr;
};
#include "Vector.tpp"
#endif // !VECTOR_H

