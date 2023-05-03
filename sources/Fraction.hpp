#include <iostream>
namespace ariel
{
    class Fraction
    {
        int numerator;
        int denominator;

    public:
        Fraction();
        Fraction(const float &frac);
        Fraction(const int &numerator, const int &denominator) : numerator(numerator), denominator(denominator){};

        int getNumerator()const
        {
            return this->numerator;
        }
        int getDenominator()const
        {
            return this->denominator;
        }

        Fraction &operator++();
        const Fraction operator++(int);
        Fraction &operator--();
        const Fraction operator--(int);
        Fraction operator-(const Fraction &frac) const;
        Fraction operator+(const Fraction &frac) const;
        Fraction operator*(const Fraction &frac) const;
        Fraction operator/(const Fraction &frac) const;

        Fraction operator*(const float &frac) const;

        friend std::ostream &operator<<(std::ostream &os, const Fraction &f)
        {
            return os;
        }

        friend std::istream &operator>>(std::istream &is, Fraction &f);

        friend Fraction operator+(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator+(const Fraction &frac2, const float &frac);
        friend Fraction operator+(const float &frac, const Fraction &frac2);

        friend Fraction operator-(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator-(const Fraction &frac2, const float &frac);
        friend Fraction operator-(const float &frac, const Fraction &frac2);

        friend bool operator>(const Fraction &frac2, const float &frac);
        friend bool operator>(const float &frac, const Fraction &frac2);
        friend bool operator>(const Fraction &frac, const Fraction &frac2);

        friend bool operator<(const Fraction &frac2, const float &frac);
        friend bool operator<(const float &frac, const Fraction &frac2);
        friend bool operator<(const Fraction &frac, const Fraction &frac2);

        friend Fraction operator*(const Fraction &frac2, const float &frac);
        friend Fraction operator*(const float &frac, const Fraction &frac2);
        

        friend Fraction operator/(const Fraction &frac2, const float &frac);
        friend Fraction operator/(const float &frac, const Fraction &frac2);

        friend bool operator<=(const Fraction &frac1, const Fraction &frac2);
        friend bool operator>=(const Fraction &frac1, const Fraction &frac2);
        friend bool operator==(const Fraction &frac1, const Fraction &frac2);
        friend bool operator<=(const Fraction &frac1, const float &frac2);
        friend bool operator>=(const Fraction &frac1, const float &frac2);
        friend bool operator==(const Fraction &frac1, const float &frac2);
    };

}