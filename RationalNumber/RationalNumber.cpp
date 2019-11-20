#include "RationalNumber.hpp"
#include <iostream>

using namespace std;

RationalNumber::RationalNumber() {
	std::cin >> *this;
	reduce();
}

RationalNumber::RationalNumber(int nominator, int denominator) {
	try {
		if (denominator == 0) {
			throw "Illegal arguments";
		}
		else if (nominator == 0) {
			this->numerator_ = 0;
			this->denominator_ = 1;
		}
		else {
			int gcd = findGCD(nominator, denominator);
			if (nominator && denominator < 0) {
				this->numerator_ = -nominator / gcd;
				this->denominator_ = -denominator / gcd;
			}
			else if (denominator < 0) {
				this->numerator_ = nominator / gcd;
				this->denominator_ = -denominator / gcd;
			}
			else {
				this->numerator_ = nominator / gcd;
				this->denominator_ = denominator / gcd;
			}
		}
	}
	catch (const char* err) {
		cerr << err << endl;
	}
}

int RationalNumber::getNumerator() const {
	return this->numerator_;
}

int RationalNumber::getDenominator() const {
	return this->denominator_;
}

void RationalNumber::setNumerator(int number) {
	this->numerator_ = number;
}

void RationalNumber::setDenominator(int number) {
	this->denominator_ = number;
}

RationalNumber& RationalNumber::operator+=(const RationalNumber& right) {
	int denominators_lcm = this->denominator_ * right.denominator_ / findGCD(this->denominator_, right.denominator_);
	int new_denominator = this->denominator_ * denominators_lcm / this->denominator_;
	int new_first_numerator = this->numerator_ * denominators_lcm / this->denominator_;
	int new_second_numerator = right.numerator_ * denominators_lcm / right.denominator_;
	this->numerator_ = new_first_numerator + new_second_numerator;
	this->denominator_ = new_denominator;
	this->reduce();
	return *this;
}

RationalNumber& RationalNumber::operator-=(const RationalNumber& right) {
	RationalNumber negative_right = RationalNumber(-right.numerator_, right.denominator_);
	*this += negative_right;
	return *this;
}

RationalNumber& RationalNumber::operator*=(const RationalNumber& right) {
	this->numerator_ = this->numerator_ * right.numerator_;
	this->denominator_ = this->denominator_ * right.denominator_;
	this->reduce();
	return *this;
}

RationalNumber& RationalNumber::operator/=(const RationalNumber& right) {
	this->numerator_ = this->numerator_ * right.denominator_;
	this->denominator_ = this->denominator_ * right.numerator_;
	this->reduce();
	return *this;
}

bool operator==(const RationalNumber& left, const RationalNumber& right) {
	return left.compare(right) == 0;
}

bool operator!=(const RationalNumber& left, const RationalNumber& right) {
	return left.compare(right) != 0;
}

bool operator>(const RationalNumber& left, const RationalNumber& right) {
	return left.compare(right) == 1;
}

bool operator<(const RationalNumber& left, const RationalNumber& right) {
	return left.compare(right) == -1;
}

bool operator>=(const RationalNumber& left, const RationalNumber& right) {
	return left.compare(right) >= 0;
}

bool operator<=(const RationalNumber& left, const RationalNumber& right) {
	return left.compare(right) <= 0;
}

const RationalNumber operator+(const RationalNumber& left, const RationalNumber& right) {
	RationalNumber result = RationalNumber(left.getNumerator(), left.getDenominator());
	result += right;
	return RationalNumber(result);
}

const RationalNumber operator-(const RationalNumber& left, const RationalNumber& right) {
	RationalNumber result = RationalNumber(left.getNumerator(), left.getDenominator());
	result -= right;
	return RationalNumber(result);
}

const RationalNumber operator*(const RationalNumber& left, const RationalNumber& right) {
	RationalNumber result = RationalNumber(left.getNumerator(), left.getDenominator());
	result *= right;
	return RationalNumber(result);
}

const RationalNumber operator/(const RationalNumber& left, const RationalNumber& right) {
	RationalNumber result = RationalNumber(left.getNumerator(), left.getDenominator());
	result /= right;
	return RationalNumber(result);
}

std::ostream& operator<< (std::ostream& out, const RationalNumber& number) {
	cout << number.getNumerator() << "/" << number.getDenominator() << endl;
	return out;
}

std::istream& operator>> (std::istream& in, RationalNumber& number) {
	int num;
	in >> num;
	int den;
	in >> den;
	number = RationalNumber(num, den);
	return in;
}

int RationalNumber::findGCD(int a, int b) const {
	int a_copy = abs(a);
	int b_copy = abs(b);
	while (a_copy != b_copy) {
		if (a_copy > b_copy) {
			int tmp = a_copy;
			a_copy = b_copy;
			b_copy = tmp;
		}
		b_copy -= a_copy;
	}
	return a_copy;
}

void RationalNumber::reduce() {
	if (numerator_ != 0) {
		int gcd = findGCD(this->numerator_, this->denominator_);
		if (this->denominator_ < 0) {
			this->numerator_ = -this->numerator_ / gcd;
			this->denominator_ = -this->denominator_ / gcd;
		}
		else {
			this->numerator_ = this->numerator_ / gcd;
			this->denominator_ = this->denominator_ / gcd;
		}
	}
}

int RationalNumber::compare(const RationalNumber& other) const {
	int denominators_lcm = this->denominator_ * other.denominator_ / findGCD(this->denominator_, other.denominator_);
	int this_numerator = this->numerator_ * denominators_lcm / this->denominator_;
	int other_numerator = other.numerator_ * denominators_lcm / other.denominator_;
	if (this_numerator < other_numerator) return -1;
	else if (this_numerator > other_numerator) return 1;
	else return 0;
}