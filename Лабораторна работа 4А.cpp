// Лабораторна работа 4А.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Area
{
protected:
	double first_side;
	double second_side;
public:
	Area (double x, double y);
	double Get_x() { return first_side; }
	double Get_y() { return second_side; }
	virtual void show_area() = 0;
	~Area()
	{
		delete &first_side, &second_side;
	}
	Area & operator = (Area & op2)
	{
		first_side = op2.Get_x();
		second_side = op2.Get_y();
		return*this;
	}
};
Area::Area(double x, double y)
{
	first_side = x;
	second_side = y;
}
class triangle :public Area {
public:
	triangle(double x, double y);
	void show_area() {
		cout << "The triangle with height ";
		cout << first_side << " and the base " << second_side;
		cout << " have an area of ";
		cout << first_side*0.5*second_side << ".\n";
	}
};
triangle::triangle(double x, double y):Area(x, y){}

class circle :public Area {
public:
	circle(double x, double y);
	void show_area(){ 
	cout << "A circle with radius ";
	cout << first_side;
	cout << " have an area of ";
    cout << first_side*first_side*3.14 << ".\n";
   }
};
circle::circle(double x, double y):Area(x, y) {}

int main()
{
	Area*p;
	triangle t(7.0,13.0);
	circle c(8.0, 0.0);
	p = &t;
	p->show_area();
	p = &c;
	p->show_area();
	

	system("pause");
    return 0;
}

