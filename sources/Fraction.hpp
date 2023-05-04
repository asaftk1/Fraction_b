#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        Fraction() : numerator(0), denominator(1) {}
        Fraction(float flo)
        {
            const int NUM_DECIMAL_PLACES = 1000;
            // Extract the integer and fractional parts of the float
            float whole = std::floor(flo);
            float fractional = std::abs(flo - whole);
            // Convert the fractional part to an integer with 3 digits after the decimal point
            int numerator = static_cast<int>(std::round(fractional * NUM_DECIMAL_PLACES));
            int denominator = NUM_DECIMAL_PLACES;
            // Add the whole part to the numerator if it's not zero
            if (whole != 0)
            {
                numerator += static_cast<int>(static_cast<float>(whole) * static_cast<float>(denominator));

            }
            // Simplify the fraction
            simplify();
            // Assign the simplified fraction to the object's member variables
            this->numerator = numerator;
            this->denominator = denominator;
        }
        Fraction(int num, int denom) 
        {
            if(denom == 0)
            {
                throw std::runtime_error("Division by zero");
            } 
            
            this->numerator = num;
            this->denominator = denom;
        }

        int getNumerator() const
        {
            return this->numerator;
        }
        int getDenominator() const
        {
            return this->denominator;
        }

        void simplify()
        {
            // Simplify the fraction by dividing the numerator and denominator by their GCD
            int gcd = std::__gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
        }

        Fraction &operator++()
        {
            numerator += denominator;
            simplify();
            return *this;
        }

        Fraction operator++(int)
        {
            Fraction old = *this;
            ++(*this);
            return old;
        }

        Fraction &operator--()
        {
            numerator -= denominator;
            simplify();
            return *this;
        }
        Fraction operator--(int)
        {
            Fraction old = *this;
            --(*this);
            return old;
        }

        Fraction operator-(const Fraction &frac) const
        {
            Fraction result;
            result.numerator = (numerator * frac.denominator) - (frac.numerator * denominator);
            result.denominator = denominator * frac.denominator;
            int gcd = std::__gcd(result.numerator, result.denominator);
            result.numerator /= gcd;
            result.denominator /= gcd;
            return result;
        }
        Fraction operator+(const Fraction &frac) const
        {
            Fraction result;
            result.numerator = (numerator * frac.denominator) + (frac.numerator * denominator);
            result.denominator = denominator * frac.denominator;
            int gcd = std::__gcd(result.numerator, result.denominator);
            result.numerator /= gcd;
            result.denominator /= gcd;
            return result;
        }
        Fraction operator*(const Fraction &frac) const
        {
            int new_num = numerator * frac.numerator;
            int new_denom = denominator * frac.denominator;
            Fraction result(new_num, new_denom);
            return result;
        }
        Fraction operator/(const Fraction &frac) const
        {
            int new_num = numerator * frac.denominator;
            int new_denom = denominator * frac.numerator;
            Fraction result(new_num, new_denom);
            return result;
        }

        // Fraction operator/(const float &flo) const
        // {
        //     float res = flo / static_cast<float>(numerator) / denominator;
        //     return Fraction(res);
        // }
        // Fraction operator*(const float &flo) const
        // {

        //     float res = flo * static_cast<float>(numerator) / denominator;
        //     return Fraction(res);
        // }

        bool operator>(const Fraction &frac) const
        {
            // First, find the least common multiple (LCM) of the denominators
            int lcm = std::lcm(denominator, frac.denominator);
            // Next, convert both fractions to have the same denominator
            int this_num = numerator * (lcm / denominator);
            int frac_num = frac.numerator * (lcm / frac.denominator);
            // Finally, compare the numerators of the two fractions
            return this_num > frac_num;
        }
        bool operator<(const Fraction &frac) const
        {
            // First, find the least common multiple (LCM) of the denominators
            int lcm = std::lcm(denominator, frac.denominator);
            // Next, convert both fractions to have the same denominator
            int this_num = numerator * (lcm / denominator);
            int frac_num = frac.numerator * (lcm / frac.denominator);
            // Finally, compare the numerators of the two fractions
            return this_num < frac_num;
        }

        bool operator==(const Fraction &frac) const
        {
            return (numerator == frac.numerator) && (denominator == frac.denominator);
        }

        bool operator<=(const Fraction &frac) const
        {
            return (*this < frac) || (*this == frac);
        }
        bool operator>=(const Fraction &frac) const
        {
            return (*this > frac) || (*this == frac);
        }

        friend std::ostream &operator<<(std::ostream &ost, const Fraction &frac);
        friend std::istream &operator>>(std::istream &ist, Fraction &frac);

        friend Fraction operator+(const Fraction &frac2, const float &flo);
        friend Fraction operator+(const float &flo, const Fraction &frac2);

        friend Fraction operator-(const Fraction &frac2, const float &flo);
        friend Fraction operator-(const float &flo, const Fraction &frac2);

        friend Fraction operator*(const Fraction &frac2, const float &flo);
        friend Fraction operator*(const float &flo, const Fraction &frac2);

        friend Fraction operator/(const Fraction &frac2, const float &flo);
        friend Fraction operator/(const float &flo, const Fraction &frac2);

        friend bool operator>(const Fraction &frac2, const float &flo);
        friend bool operator>(const float &flo, const Fraction &frac2);

        friend bool operator<(const Fraction &frac2, const float &flo);
        friend bool operator<(const float &flo, const Fraction &frac2);

        friend bool operator<=(const Fraction &frac1, const float &flo);
        friend bool operator<=(const float &flo, const Fraction &frac1);

        friend bool operator>=(const Fraction &frac1, const float &flo);
        friend bool operator>=(const float &flo, const Fraction &frac1);

        friend bool operator==(const Fraction &frac1, const float &flo);
        friend bool operator==(const float &flo, const Fraction &frac1);
    };

}
#endif