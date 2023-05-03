#include "Fraction.hpp"
#include <algorithm>
using namespace ariel;
////// + operator implementation ////////////////////
// Fraction operator+(const Fraction &frac1, const Fraction &frac2)
// {
//     int nn = frac1.getNumerator() * frac2.getDenominator() +
//              frac1.getDenominator() * frac2.getNumerator();
//     int dd = frac1.getDenominator() * frac2.getDenominator();
//     return Fraction(nn, dd);
// }

Fraction Fraction::operator+(const Fraction &frac) const
{
    Fraction result;
    result.numerator = (numerator * frac.denominator) - (frac.numerator * denominator);
    result.denominator = denominator * frac.denominator;
    int gcd = std::__gcd(result.numerator, result.denominator);
    result.numerator /= gcd;
    result.denominator /= gcd;
    return result;
}

Fraction operator+(const Fraction &frac2, const float &frac)
{
    return Fraction(frac + static_cast<float>(frac2.getNumerator()) / frac2.getDenominator());
}

Fraction operator+(const float &frac, const Fraction &frac2)
{
    return Fraction(frac + static_cast<float>(frac2.getNumerator()) / frac2.getDenominator());
}

////// - operator implementation ///////////////////
// Fraction operator-(const Fraction &frac1, const Fraction &frac2)
// {
//     int nn = frac1.getNumerator() * frac2.getDenominator() -
//              frac1.getDenominator() * frac2.getNumerator();
//     int dd = frac1.getDenominator() * frac2.getDenominator();
//     return Fraction(nn, dd);
// }
Fraction Fraction ::operator-(const Fraction &frac) const
{
    Fraction result;
    result.numerator = (numerator * frac.denominator) - (frac.numerator * denominator);
    result.denominator = denominator * frac.denominator;
    int gcd = std::__gcd(result.numerator, result.denominator);
    result.numerator /= gcd;
    result.denominator /= gcd;
    return result;
}

Fraction operator-(const Fraction &frac2, const float &frac)
{
    return Fraction(frac - static_cast<float>(frac2.getNumerator()) / frac2.getDenominator());
}

Fraction operator-(const float &frac, const Fraction &frac2)
{
    return Fraction(frac - static_cast<float>(frac2.getNumerator()) / frac2.getDenominator());
}

////// * operator implementation ////////////////////

Fraction Fraction::operator*(const Fraction &frac) const
{
}
