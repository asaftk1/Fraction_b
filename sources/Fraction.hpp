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
            
            // Assign the simplified fraction to the object's member variables
            this->numerator = numerator;
            this->denominator = denominator;
            // Simplify the fraction
            simplify();
        }
        Fraction(const int num, int denom) :numerator(num), denominator(denom)
        {
             if (denom == 0) {
                throw std::invalid_argument("Invalid argument: denominator cannot be zero.");
            }
            if(denominator < 0 && numerator >0) 
            {
                denominator *= -1;
                numerator *= -1;
            }
             simplify();
        }

        
        int getNumerator() const
        {
            return numerator;
        }
        int getDenominator() const
        {
            return denominator;
        }
        


        void simplify()
        {
            if(numerator <0 && denominator <0)
            {
                numerator *= -1;
                denominator *= -1;
            }
            // Simplify the fraction by dividing the numerator and denominator by their GCD
            int gcd = std::__gcd(abs(numerator), abs(denominator));
        
            numerator /= gcd;
            denominator /= gcd;
           
        }

        ///////////////////// ++ operator ///////////////////////////////////////
        Fraction &operator++()
        {
            numerator += denominator;
            simplify();
            return *this;
        }

        ///////////////////// ++ operator ///////////////////////////////////////
        Fraction operator++(int)
        {
            Fraction old = *this;
            ++(*this);
            return old;
        }

        ///////////////////// -- operator ///////////////////////////////////////
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

        ///////////////////// - operator ///////////////////////////////////////
        Fraction operator-(const Fraction &frac) const
        {
            int64_t new_num = static_cast<int64_t>(numerator) * static_cast<int64_t>(frac.denominator) - static_cast<int64_t>(frac.numerator)*static_cast<int64_t>(denominator);
            int64_t new_denom = static_cast<int64_t>(denominator) * static_cast<int64_t>(frac.denominator);

           if (new_num > std::numeric_limits<int>::max() || new_num < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Arithmetic overflow");
            }

            if (new_denom > std::numeric_limits<int>::max() || new_denom < std::numeric_limits<int>::min()) {
                throw std::overflow_error("Arithmetic overflow");
            }

            Fraction result(static_cast<int>(new_num), static_cast<int>(new_denom));
            result.simplify();
            return result;
        }


        ///////////////////// + operator ///////////////////////////////////////
        Fraction operator+(const Fraction &frac) const
        {
           
            int64_t new_num = static_cast<int64_t>(numerator) * static_cast<int64_t>(frac.denominator)+ static_cast<int64_t>(frac.numerator)*static_cast<int64_t>(denominator);
            int64_t new_denom = static_cast<int64_t>(denominator) * static_cast<int64_t>(frac.denominator);

           if (new_num > std::numeric_limits<int>::max() || new_num < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Arithmetic overflow");
            }

            if (new_denom > std::numeric_limits<int>::max() || new_denom < std::numeric_limits<int>::min()) {
                throw std::overflow_error("Arithmetic overflow");
            }

            Fraction result(static_cast<int>(new_num), static_cast<int>(new_denom));
            result.simplify();
            return result;
        }
    

        ///////////////////// * operator ///////////////////////////////////////
        Fraction operator*(const Fraction &frac) const
    {
    int64_t new_num = static_cast<int64_t>(numerator) * static_cast<int64_t>(frac.numerator);
    int64_t new_denom = static_cast<int64_t>(denominator) * static_cast<int64_t>(frac.denominator);

    if (new_num > std::numeric_limits<int>::max() || new_num < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Arithmetic overflow");
    }

    if (new_denom > std::numeric_limits<int>::max() || new_denom < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Arithmetic overflow");
    }

    Fraction result(static_cast<int>(new_num), static_cast<int>(new_denom));
    result.simplify();
    return result;
}


        /////////////////////   / operator ///////////////////////////////////////
  Fraction operator/(const Fraction &frac) const
        {
            if(frac.getNumerator() == 0)
            {
                throw std::runtime_error("Invalid argument: denominato");
            }
             int64_t new_num = static_cast<int64_t>(numerator) * static_cast<int64_t>(frac.denominator);
            int64_t new_denom = static_cast<int64_t>(denominator) * static_cast<int64_t>(frac.numerator);
           

            if (new_num > std::numeric_limits<int>::max() || new_num < std::numeric_limits<int>::min()) {
                throw std::overflow_error("Arithmetic overflow");
            }

            if (new_denom > std::numeric_limits<int>::max() || new_denom < std::numeric_limits<int>::min()) {
                throw std::overflow_error("Arithmetic overflow");
            }

             Fraction result(static_cast<int>(new_num), static_cast<int>(new_denom));
            result.simplify();
             return result;
            
        }
      



        ///////////////////// > operator ///////////////////////////////////////
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
        
        ///////////////////// < operator ///////////////////////////////////////
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

        ///////////////////// == operator ///////////////////////////////////////
bool operator==(const Fraction &frac) const
        {
            if(numerator ==0 && frac.numerator == 0)
            {
                return true;
            }
            return (numerator == frac.numerator) && (denominator == frac.denominator);
        }


        ///////////////////// <= operator ///////////////////////////////////////
bool operator<=(const Fraction &frac) const
        {
            return (*this < frac) || (*this == frac);
        }
        
        ///////////////////// >= operator ///////////////////////////////////////
bool operator>=(const Fraction &frac) const
        {
            return (*this > frac) || (*this == frac);
        }



        ///////////////////// friend functions ///////////////////////////////////////
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