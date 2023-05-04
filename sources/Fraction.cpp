
#include <algorithm>
#include <iostream>
#include "Fraction.hpp"

using namespace ariel;
using namespace std;
/////////////////////////// + operator implementation ////////////////////

Fraction ariel::operator+(const ariel::Fraction &frac2, const float &flo)
{
    return Fraction(flo + static_cast<float>(frac2.getNumerator()) / frac2.getDenominator());
}

Fraction ariel::operator+(const float &flo, const ariel::Fraction &frac2)
{
    return Fraction(flo + static_cast<float>(frac2.getNumerator()) / frac2.getDenominator());
}

/////////////////////////// - operator implementation ///////////////////

Fraction ariel::operator-(const ariel::Fraction &frac2, const float &flo)
{
    return Fraction(flo - static_cast<float>(frac2.getNumerator()) / frac2.getDenominator());
}

Fraction ariel::operator-(const float &flo, const ariel::Fraction &frac2)
{
    return Fraction(flo - static_cast<float>(frac2.getNumerator()) / frac2.getDenominator());
}

/////////////////////////// * operator implementation ////////////////////
Fraction ariel::operator*(const ariel::Fraction &frac, const float &flo)
{
    float result = static_cast<float>(frac.getNumerator()) * flo / frac.getDenominator();
    return Fraction(result);
}
Fraction ariel::operator*(const float &flo, const ariel::Fraction &frac2)
{
    float result = static_cast<float>(frac2.getNumerator()) * flo / frac2.getDenominator();
    return Fraction(result);
}
/////////////////////////// * operator implementation ////////////////////
Fraction ariel::operator/(const ariel::Fraction &frac2, const float &flo)
{
     float result = frac2.getNumerator() / frac2.getDenominator() / flo;
    return Fraction(result);
}
Fraction ariel::operator/(const float &flo, const ariel::Fraction &frac2)
{
 float result = frac2.getNumerator() / frac2.getDenominator() / flo;
    return Fraction(result);
}


/////////////////////////// IO operators implementation ////////////////////
std::ostream &ariel::operator<<(std::ostream &ost, const ariel::Fraction &frac)
{
    ost << frac.getNumerator() << "/" << frac.getDenominator();
    return ost;
}


std::istream &ariel::operator>>(std::istream &ist, ariel::Fraction &frac)
{
    char delimiter;
    int numerator, denominator;
    ist >> numerator >> delimiter >> denominator;
    frac = Fraction(numerator, denominator);
    return ist;
}

/////////////////////////// Boolean operators implementation ////////////////////

bool ariel::operator>(const ariel::Fraction &frac2, const float &flo)
{
    float f1 = static_cast<float>(frac2.getNumerator()) / frac2.getDenominator();
    return f1 > flo;
}
bool ariel::operator>(const float &flo, const ariel::Fraction &frac2)
{
    float f1 = static_cast<float>(frac2.getNumerator()) / frac2.getDenominator();
    return f1 < flo;
}

bool ariel::operator<(const ariel::Fraction &frac2, const float &flo)
{
    float f1 = static_cast<float>(frac2.getNumerator()) / frac2.getDenominator();
    return f1 < flo;
}
bool ariel::operator<(const float &flo, const ariel::Fraction &frac2)
{
    float f1 = static_cast<float>(frac2.getNumerator()) / frac2.getDenominator();
    return f1 > flo;
}


bool ariel::operator<=(const ariel::Fraction &frac1, const float &flo)
{
    float f = static_cast<float>(frac1.getNumerator()) / frac1.getDenominator();
    return flo <= f;
}

bool ariel::operator<=(const float& flo, const ariel::Fraction& frac2)
{
    float f = static_cast<float>(frac2.getNumerator()) / frac2.getDenominator();
    return flo <= f;
}


bool ariel::operator>=(const ariel::Fraction &frac1, const float &flo)
{
    float f = static_cast<float>(frac1.getNumerator()) / frac1.getDenominator();
    return flo >= f;
}
bool ariel::operator>=(const float &flo, const ariel::Fraction &frac1)
{
    float f = static_cast<float>(frac1.getNumerator()) / frac1.getDenominator();
    return flo >= f;
}

bool ariel::operator==(const ariel::Fraction &frac1, const float &flo)
{
    float f = static_cast<float>(frac1.getNumerator()) / frac1.getDenominator();
    return flo == f;
}

bool ariel::operator==(const float &flo, const ariel::Fraction &frac1)
{
    float f = static_cast<float>(frac1.getNumerator()) / frac1.getDenominator();
    return flo == f;
}
