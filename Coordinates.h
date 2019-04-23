#pragma once

class Coordinates {
	int *x;
	int *y;
	int *z;
public:
	friend Coordinates operator++(Coordinates &op, int);
	friend Coordinates &operator--(Coordinates &op);
	Coordinates &operator++();
	Coordinates operator--(int);
	Coordinates();
	explicit Coordinates(int val, int val2, int val3);
	~Coordinates();
	Coordinates(const Coordinates &obj);
	void pin();
};