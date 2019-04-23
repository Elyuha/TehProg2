#pragma once
#include "cyclicQueue.h"
#include <iostream>
#include <ctime>

using namespace std;

CyclicQ::CyclicQ() {
	last = NULL;
	first = NULL;
	num = 0;
}

CyclicQ::~CyclicQ() {
	elem *temp;
	for (int i = 0; i < num; i++) {
		temp = last->prev;
		delete last;
		last = temp;
	}
}

CyclicQ::CyclicQ(const CyclicQ &ob) {
	last = NULL;
	first = NULL;
	num = 0;
	elem *temp = ob.last;
	int *tmp = new int[ob.num];
	int i = ob.num - 1;
	tmp[i] = temp->value;
	i--;
	while (temp != ob.first) {
		temp = temp->prev;
		tmp[i] = temp->value;
		i--;
	}
	for (i = ob.num - 1; i >= 0; i--)
		this->add(tmp[i]);
	delete[] tmp;
}

void CyclicQ::add(int val) {
	elem *temp = new elem;
	temp->prev = last;
	temp->value = val;
	if (num == 0) {
		first = temp;
	}
	last = temp;
	first->prev = last;
	num++;
}

void CyclicQ::pin() {
	elem *temp = last;
	int *tmp = new int[num];
	int i = num - 1;
	tmp[i] = temp->value;
	i--;
	while (temp != first) {
		temp = temp->prev;
		tmp[i] = temp->value;
		i--;
	}
	cout << "Общее кол-во элементо в очереди: " << num << endl;
	for (i = 0; i < num; i++)
		printf("%-4d", tmp[i]);
	cout << endl;
	delete[] tmp;
}

CyclicQ CyclicQ::operator+(const CyclicQ &ob1) {
	CyclicQ a;
	elem *temp1 = this->last;
	elem *temp2 = ob1.last;
	for (int i = num - 1; i > 0; i--) {
		a.add(temp1->value + temp2->value);
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	a.add(temp1->value + temp2->value);
	return a;
}

CyclicQ CyclicQ::operator-(const CyclicQ &ob1) {
	CyclicQ a;
	elem *temp1 = this->last;
	elem *temp2 = ob1.last;
	int t;
	for (int i = num - 1; i > 0; i--) {
		t = temp1->value - temp2->value;
		a.add(t);
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	t = temp1->value - temp2->value;
	a.add(t);
	return a;
}

CyclicQ CyclicQ::operator*(const CyclicQ &ob1) {
	CyclicQ a;
	elem *temp1 = this->last;
	elem *temp2 = ob1.last;
	for (int i = num - 1; i > 0; i--) {
		a.add(temp1->value * temp2->value);
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	a.add(temp1->value * temp2->value);
	return a;
}

CyclicQ CyclicQ::operator/(const CyclicQ &ob1) {
	CyclicQ a;
	elem *temp1 = this->last;
	elem *temp2 = ob1.last;
	for (int i = num - 1; i > 0; i--) {
		a.add(temp1->value / temp2->value);
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	a.add(temp1->value / temp2->value);
	return a;
}

CyclicQ &CyclicQ::operator=(const CyclicQ &ob) {
	elem *temp1 = last;
	elem *temp2 = ob.last;
	for (int i = num; i > 0; i--) {
		temp1->value = temp2->value;
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	return *this;
}

CyclicQ &operator+=(CyclicQ &ob1, const int val) {
	elem *temp = ob1.last;
	for (int i = ob1.num; i > 0; i--) {
		temp->value += val;
		temp = temp->prev;
	}
	return ob1;
}

CyclicQ &operator-=(CyclicQ &ob1, const int val) {
	elem *temp = ob1.last;
	for (int i = ob1.num; i > 0; i--) {
		temp->value -= val;
		temp = temp->prev;
	}
	return ob1;
}

CyclicQ &operator*=(CyclicQ &ob1, const int val) {
	elem *temp = ob1.last;
	for (int i = ob1.num; i > 0; i--) {
		temp->value *= val;
		temp = temp->prev;
	}
	return ob1;
}

CyclicQ &operator/=(CyclicQ &ob1, const int val) {
	elem *temp = ob1.last;
	for (int i = ob1.num; i > 0; i--) {
		temp->value /= val;
		temp = temp->prev;
	}
	return ob1;
}