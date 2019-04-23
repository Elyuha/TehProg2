#pragma once
#include "Elem.h"
#include <ctime>

class CyclicQ {
	elem *last;
	elem *first;
	int num;
public:
	CyclicQ();
	~CyclicQ();
	CyclicQ(const CyclicQ &ob);
	void add(int val);
	void pin();
	CyclicQ operator+(const CyclicQ &ob1);
	CyclicQ operator-(const CyclicQ &ob1);
	CyclicQ operator*(const CyclicQ &ob1);
	CyclicQ operator/(const CyclicQ &ob1);
	CyclicQ &operator=(const CyclicQ &ob);
	friend CyclicQ &operator+=(CyclicQ &ob1, const int val);
	friend CyclicQ &operator-=(CyclicQ &ob1, const int val);
	friend CyclicQ &operator*=(CyclicQ &ob1, const int val);
	friend CyclicQ &operator/=(CyclicQ &ob1, const int val);
 };