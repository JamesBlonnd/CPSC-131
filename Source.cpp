#include <iostream>
#include "header.h"
using namespace std;


class PolyArray
{
public:
	PolyArray();//constructor
	PolyArray(double coeffArray[], int arraysize);  // degree = arraysize -1;
	PolyArray(const PolyArray& poly);
	~PolyArray();//destructor
	double evaluate(const double& x) const;
private:
	double *coeff;     // coefficients of polynomial function
	int n;            // degree of polynomial function 

};

PolyArray::PolyArray() {   // default constructor
	n = 0;
	coeff = new double[n + 1];  // dynamically create an array of size 1
	coeff[0] = 0.0;
}
PolyArray::PolyArray(const PolyArray & poly) {   // Copy constructor

	n = poly.n;
	coeff = poly.coeff;
}
double PolyArray::evaluate(const double& x) const
{
	double total = 0.0;
	for (int i = 0; i <= n; i++)
	{
		total += coeff[i] * pow(x, i);
	}
	return total;
}
PolyArray::~PolyArray()//destructor
{
	delete coeff;
	coeff = NULL;
}

class PolyTerm {
private:
	int _order;
	double _coeff;

public:
	void setOrder(int order) {
		_order = order;
	}
	void setCoeff(double coeff) {
		_coeff = coeff;
	}
	int getOrder() {
		return _order;
	}
	double getCoeff() {
		return _coeff;
	}
};



int main()
{
	// polynomial function y = 3.5*x^7 + 2.2 using array
	// this function is the same as 2.2*x^0 + 0*x^1 + 0*x^2 + 0*x^3 + 0*x^4 + 0*x^5 + 0*x^6 + 3.5*x^7

	double coeffArray[8] = { 2.2, 0, 0, 0, 0, 0, 0, 3.5 };
	PolyArray polyArray(coeffArray, 8);
	cout << polyArray.evaluate(1.0) << endl;
	cout << polyArray.evaluate(2.0) << endl;


	// polynomial function y = 3.5*x^7 + 2.2 using linked list 
	SLinkedList<PolyTerm> polyLinkedList;

	// develop your initialization part here

	cout << polyLinkedList.evaluate(1.0) << endl;
	cout << polyLinkedList.evaluate(2.0) << endl;

	return 0;
}
