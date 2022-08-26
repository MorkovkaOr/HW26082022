#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


class Fractions
{
	double integer_part;
	double numerator;
	double denominator;
public:
	double get_integer_part()const
	{
		return integer_part;
	}
	double get_numerator()const
	{
		return numerator;
	}
	double get_denominator()const
	{
		return denominator;
	}
	void set_integer_part(double integer_part)
	{
		this->integer_part = integer_part;
	}
	void set_numerator(double numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(double denominator)
	{
		this->denominator = denominator;
	}

	//				Constructors:

	//Fractions(int integer_part = 0, double numerator = 0, double denominator = 0)
	//{
	//	this->integer_part = integer_part;
	//	this->numerator = numerator;
	//	this->denominator = denominator;
	//
	//	cout << "Constructor:\t" << this << endl;
	//}
	Fractions(double numerator = 0, double denominator = 1, double integer_part = 0)
	{
		this->numerator = numerator;
		this->denominator = denominator;
		this->integer_part = integer_part;
		cout << "Constructor:\t" << this << endl;
	}
	~Fractions()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//				Operators:
	Fractions& operator=(const Fractions& other)
	{
		this->integer_part = other.integer_part;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}


	//				Methods:

	void print()const
	{
		if (numerator == 0)
		{
			cout << integer_part << endl;
		}
		else if (integer_part != 0)
		{
			cout << integer_part << " " << numerator << "/" << denominator << endl;
		}
		else
		{
			cout << numerator << "/" << denominator << endl;
		}
	}
	Fractions Sub(Fractions f1, Fractions f2)
	{
		Fractions f3;
		f3.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
	}
	Fractions Sum(Fractions f1, Fractions f2)
	{
		Fractions f3;
		f3.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
	}
	Fractions Mult(Fractions f1, Fractions f2)
	{
		Fractions f3;
		f3.numerator = f1.numerator * f2.numerator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
	}
	Fractions Div(Fractions f1, Fractions f2)
	{
		Fractions f3;
		f3.numerator = f1.numerator * f2.denominator;
		f3.denominator = f1.denominator * f2.numerator;
		return f3;
	}
	Fractions Pow(Fractions f, int n)
	{
		Fractions f2;
		f2.numerator = 1;
		f2.denominator = 1;
		for (int i = 0; i < n; i++)
		{
			f2.numerator *= f.numerator;
			f2.denominator *= f.denominator;
		}
		return f2;
	}
	bool Equals(Fractions f1, Fractions f2)
	{
		f1.numerator *= f2.denominator;

		f2.numerator *= f1.denominator;

		return f1.numerator == f2.numerator;
	}
	bool NotEquals(Fractions f1, Fractions f2)
	{
		return!Equals(f1, f2);
	}
	bool Less(Fractions f1, Fractions f2)
	{
		f1.numerator *= f2.denominator;

		f2.numerator *= f1.denominator;

		return f1.numerator < f2.numerator;
	}
	bool More(Fractions f1, Fractions f2)
	{
		f1.numerator *= f2.denominator;

		f2.numerator *= f1.denominator;

		return f1.numerator > f2.numerator;
	}
	Fractions Square(Fractions f)
	{
		f.numerator = sqrt(f.numerator);
		f.denominator = sqrt(f.denominator);
		return f;
	}
	double Decimal(Fractions f)
	{
		return f.numerator / f.denominator;
	}
	Fractions IntSelection(Fractions& f1)
	{

		f1.integer_part = (int)(f1.numerator / f1.denominator);
		f1.numerator -= f1.integer_part * f1.denominator;
		return 0;
	}
	bool LessOrEquals(Fractions f1, Fractions f2)
	{
		f1.numerator *= f2.denominator;

		f2.numerator *= f1.denominator;

		return f1.numerator <= f2.numerator;
	}
	bool MoreOrEquals(Fractions f1, Fractions f2)
	{
		f1.numerator *= f2.denominator;

		f2.numerator *= f1.denominator;

		return f1.numerator >= f2.numerator;
	}
	Fractions Reduction(Fractions& f1)
	{
		f1.IntSelection(f1);
		int  num = f1.numerator, den = f1.denominator, remains = num;
		do {
			num = remains;
			remains = den % num;
			den = num;
		} while (remains != 0);
		f1.numerator /= num;
		f1.denominator /= num;
		return 0;
	}
};


void main()
{
	setlocale(LC_ALL, "");
	setlocale(LC_ALL, "");
	Fractions A, B, C, D, F;
	A = Fractions(111, 432);
	B = Fractions(4, 2);
	C = A.Sub(A, B);
	C.print();
	C = A.Mult(A, B);
	C.print();
	C = A.Square(A);
	C.print();
	A.IntSelection(B);
	B.print();
	C = A.LessOrEquals(A, B);
	C.print();
	C = A.More(A, B);
	C.print();
	A.Reduction(A);
	A.print();
}