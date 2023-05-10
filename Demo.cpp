/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(5,3), b(14,21),d(0.3333);
    cout << "d: "<< d << endl;
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a+b << endl; 
    cout << "a-b" << a-b << endl; 
    cout << "a/b" << a/b << endl; 
    cout << "a*b" << a*b << endl; 
    cout << "2.3*b" << 2.3*b << endl; 
    cout << "a+2.421" << a+2.421 << endl; 
    Fraction c = a+b-1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;
//////////////////this is my demo/////////////
Fraction frac1(1,2), frac2(3,6), frac3(0.5), frac4(-0.5);
if(frac1 == frac2){
    cout<< "1/2 = 3/6 "<<endl;
}
else{cout<<"something went wrong with simplifing the fraction "<<endl;}
if(frac1 == frac3){
    cout<< "1/2 =0.5"<<endl;
}
else{cout<<"something went wrong with == operator compareing with flot "<<endl;}

if(frac1 + frac2 != 1){cout << "+  operator is wrong when using 2 fractions"<<endl;}
else cout<<"+ operator with 2 fraction works fine"<<endl;

if(frac1 + frac3 != 1){cout << "+  operator is wrong when using adding float to fraction"<<endl;}
else cout<<"+ operator with fraction and float works fine"<<endl;

if(frac1 - frac2 != 0){cout << "-  operator is wrong when using 2 fractions"<<endl;}
else cout<<"- operator with 2 fraction works fine"<<endl;

if(frac1 - frac3 != 0){cout << "-  operator is wrong when using adding float to fraction"<<endl;}
else cout<<"- operator with fraction and float works fine"<<endl;

if(frac1 * frac2 != Fraction(1,4)){cout << "*  operator is wrong when using 2 fractions"<<endl;}
else cout<<"* operator with 2 fraction works fine"<<endl;

if(frac1 * frac3 != Fraction(1,4)){cout << "*  operator is wrong when using using fraction and float"<<endl;}
else cout<<"* operator with fraction and float works fine"<<endl;

if(frac1 / frac2 != Fraction(1,2)){cout << "'/' operator is wrong when using 2 fractions"<<endl;}
else cout<<"/ operator with 2 fraction works fine"<<endl;

if(frac1 / frac3 != Fraction(1,2)){cout << "'/' operator is wrong when using using fraction and float"<<endl;}
else cout<<"/ operator with fraction and float works fine"<<endl;

if(frac1 == frac2){cout<<"== operator is correct"<<endl;}
else{cout<< "someting in wrong with == operator"<<endl;}

if(frac1 != frac2-Fraction(0.1243213)){cout<<"!= operator is correct"<<endl;}
else{cout<< "someting in wrong with != operator"<<endl;}

if(frac1 <= frac2 && frac1 <= frac1+Fraction(1,2) && frac1<= 0.5123){cout<<"<= operator is correct"<<endl;}
else{cout<< "someting in wrong with <= operator"<<endl;}

if(frac1 >= frac2 && frac1 >= frac1-Fraction(1,2) && frac1 >= 0){cout<<">= operator is correct"<<endl;}
else{cout<< "someting in wrong with >= operator"<<endl;}






}
