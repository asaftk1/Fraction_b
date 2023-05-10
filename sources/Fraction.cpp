
#include <algorithm>
#include <iostream>
#include "Fraction.hpp"

using namespace ariel;
using namespace std;

/////////////////////////// + operator implementation ////////////////////
/*
    This functions creats a new Fraction from the float frovided and then uses the
     + operator that was implemented in the hpp file for 2 fractions;
     returns a simplifyed Fraction
*/
Fraction ariel::operator+(const ariel::Fraction &frac2, const float &flo)
{
    Fraction f(flo);
    Fraction res;
    res = frac2 + f;
    res.simplify();
    return res;
}

Fraction ariel::operator+(const float &flo, const ariel::Fraction &frac2)
{
    Fraction f(flo);
    Fraction res;
    res = frac2 + f;
    res.simplify();
    return res;
}

/////////////////////////// - operator implementation ///////////////////
/*
     This functions creats a new Fraction from the float frovided and then uses the
     - operator that was implemented in the hpp file for 2 fractions;
     returns a simplifyed Fraction
*/
Fraction ariel::operator-(const ariel::Fraction &frac2, const float &flo)
{
    Fraction f(flo);
    Fraction res;
    res = frac2 - f;
    res.simplify();
    return res;
}

Fraction ariel::operator-(const float &flo, const ariel::Fraction &frac2)
{
    Fraction f(flo);
    Fraction res;
    res = f - frac2;
    res.simplify();
    return res;
}

/////////////////////////// * operator implementation ////////////////////
/*
     This functions creats a new Fraction from the float frovided and then uses the
     * operator that was implemented in the hpp file for 2 fractions;
     returns a simplifyed Fraction
*/
Fraction ariel::operator*(const ariel::Fraction &frac, const float &flo)
{
    Fraction f(flo);
    Fraction res;
    res = frac * f;
    res.simplify();
    return res;
}
Fraction ariel::operator*(const float &flo, const ariel::Fraction &frac2)
{
    Fraction f(flo);
    Fraction res;
    res = frac2 * f;
    res.simplify();
    return res;
}
///////////////////////////   / operator implementation ////////////////////
/*
     This functions first checks if the float provided is "0" if so an exaption is thown,
     else creats a new Fraction from the float frovided and then uses the
     - operator that was implemented in the hpp file for 2 fractions;
     returns a simplifyed Fraction
*/
Fraction ariel::operator/(const ariel::Fraction &frac2, const float &flo)
{
    if (flo == 0)
    {
        throw std::runtime_error("Division by zero");
    }
    Fraction f(flo);
    Fraction res;
    res = frac2 / f;
    res.simplify();
    return res;
}

Fraction ariel::operator/(const float &flo, const ariel::Fraction &frac2)
{
    // if the fraction frovided is "0" then the Fraction constracut will throw exaption.
    Fraction result(Fraction(flo) / frac2);
    result.simplify();
    return result;
}

/////////////////////////// IO operators implementation ////////////////////
std::ostream &ariel::operator<<(std::ostream &ost, const ariel::Fraction &frac)
{
    ost << frac.getNumerator() << "/" << frac.getDenominator();
    return ost;
}

std::istream &ariel::operator>>(std::istream &in, Fraction &fraction)
{
    int numerator = 0, denominator = 1;
    char delimiter = '/';

    // Read the numerator
    if (!(in >> numerator))
    {
        in.setstate(std::ios_base::failbit);
        throw std::runtime_error("Invalid input format for Fraction");
    }

    // Check for a delimiter or whitespace before the denominator
    char c = in.peek();
    if (c == delimiter)
    {
        in.get();
    }
    else if (std::isspace(c))
    {
        in.ignore();
        // Skip any additional whitespace
        while (std::isspace(in.peek()))
        {
            in.ignore();
        }
    }
    else
    {
        in.setstate(std::ios_base::failbit);
        throw std::runtime_error("Invalid input format for Fraction");
    }

    // Read the denominator
    if (!(in >> denominator))
    {
        in.setstate(std::ios_base::failbit);
        return in;
    }
    // checks for wrong input such as denominator = 0
    if (denominator == 0)
    {
        throw std::runtime_error("Invalid input format for Fraction");
    }
    // creats the fraction with the input provided
    fraction = Fraction(numerator, denominator);
    return in;
}

/////////////////////////// Boolean operators implementation ////////////////////

/*
    in each of this function the fraction in being cast to float,
    returns boolean for the standart float operations.
*/
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
    return f <= flo;
}

bool ariel::operator<=(const float &flo, const ariel::Fraction &frac2)
{
    float f = static_cast<float>(frac2.getNumerator()) / frac2.getDenominator();
    return flo <= f;
}

bool ariel::operator>=(const ariel::Fraction &frac1, const float &flo)
{
    float f = static_cast<float>(frac1.getNumerator()) / frac1.getDenominator();
    return f >= flo;
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
