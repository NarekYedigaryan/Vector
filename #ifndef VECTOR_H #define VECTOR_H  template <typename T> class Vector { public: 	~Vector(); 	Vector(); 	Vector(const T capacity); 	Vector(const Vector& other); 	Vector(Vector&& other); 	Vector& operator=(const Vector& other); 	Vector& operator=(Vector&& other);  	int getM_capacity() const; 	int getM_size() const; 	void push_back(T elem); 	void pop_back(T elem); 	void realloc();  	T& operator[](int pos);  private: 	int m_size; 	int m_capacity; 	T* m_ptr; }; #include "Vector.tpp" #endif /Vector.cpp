#include "Vector.h"
template <typename T>
Vector<T>::Vector() :m_capacity(), m_size(), m_ptr(nullptr) {};
template <typename T>
Vector<T>::Vector(const T capacity) :m_capacity(capacity), m_size(), m_ptr(nullptr) {};
template <typename T>
Vector<T>::Vector(const Vector& other) :

	m_capacity(other.m_capacity),
	m_size(other.m_size)
{
	m_ptr = new T[m_capacity];
	for (int i = 0; i < m_size; ++i) {
		m_ptr[i] = other.m_ptr[i];
	}
}
template <typename T>

Vector<T>::Vector(Vector&& other)
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_ptr = other.m_ptr;

	other.m_size = {};
	other.m_capacity = {};
	other.m_ptr = { nullptr };
}
template <typename T>

Vector<T>& Vector<T>::operator=(const Vector& other)
{
	m_size = (other.m_size);
	m_capacity = (other.m_capacity);
	delete[] m_ptr;
	m_ptr = new T[m_capacity];
	for (int i = 0; i < m_size; ++i) {
		m_ptr[i] = other.m_ptr[i];
	}
	return *this;
}
template <typename T>

Vector<T>& Vector<T>::operator=(Vector&& other)
{
	m_size = { other.m_size };
	m_capacity = { other.m_capacity };
	delete[] m_ptr;
	m_ptr = { other.m_ptr };
	other.m_size = {};
	other.m_capacity = {};
	other.m_ptr = { nullptr };
	return *this;
}
template <typename T>

void Vector<T>::realloc()
{
	T* tmp = new T[m_capacity * 2];
	m_capacity *= 2;
	for (int i = 0; i < m_size; ++i) {
		tmp[i] = m_ptr[i];
	}
	delete[]m_ptr;
	m_ptr = tmp;
}
template <typename T>

void Vector<T>::push_back(T elem)
{
	if (!m_ptr) {
		m_ptr = new T[1];
		m_capacity = 1;
	}
	else if (m_size == m_capacity) {
		realloc();
	}
	m_ptr[m_size] = elem;
	++m_size;
}
template <typename T>

void Vector<T>::pop_back(T elem)
{
	if (m_size > 0) {
		--m_size;
	}
}
template <typename T>

T Vector<T>::getM_capacity() const
{
	return m_capacity;
}
template <typename T>

T Vector<T>::getM_size() const
{
	return m_size;
}
template <typename T>

Vector<T>::~Vector()
{
	delete[] m_ptr;
}
