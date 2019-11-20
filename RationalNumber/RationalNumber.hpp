#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

#include <iostream>

class RationalNumber {
public:
	RationalNumber();

	RationalNumber(int numerator, int denominator);

	int getNumerator() const;

	int getDenominator() const;

	void setNumerator(int number);

	void setDenominator(int number);

	RationalNumber& operator+=(const RationalNumber& right);

	RationalNumber& operator-=(const RationalNumber& right);

	RationalNumber& operator*=(const RationalNumber& right);

	RationalNumber& operator/=(const RationalNumber& right);

	friend bool operator==(const RationalNumber& left, const RationalNumber& right);

	friend bool operator!=(const RationalNumber& left, const RationalNumber& right);

	friend bool operator>(const RationalNumber& left, const RationalNumber& right);

	friend bool operator<(const RationalNumber& left, const RationalNumber& right);

	friend bool operator>=(const RationalNumber& left, const RationalNumber& right);

	friend bool operator<=(const RationalNumber& left, const RationalNumber& right);

	friend const RationalNumber operator+(const RationalNumber& left, const RationalNumber& right);

	friend const RationalNumber operator-(const RationalNumber& left, const RationalNumber& right);

	friend const RationalNumber operator*(const RationalNumber& left, const RationalNumber& right);

	friend const RationalNumber operator/(const RationalNumber& left, const RationalNumber& right);

	friend std::ostream& operator<< (std::ostream& out, const RationalNumber& number);

	friend std::istream& operator>> (std::istream& in, RationalNumber& number);


private:
	int numerator_;
	int denominator_;

	int findGCD(int a, int b) const;

	void reduce();

	int compare(const RationalNumber& other) const;
};

#endif
