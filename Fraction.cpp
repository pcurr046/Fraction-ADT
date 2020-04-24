//Patricia Curry
//4/17/2020
//CS10B - Sujan Sarkar
//Project 2
//file: Fraction.cpp

#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Fraction.h"
using namespace std;

namespace cs10b_fraction{

    /***********************************************************************************
     *This is the parametized constructor. It initialies an object and sets both of    *
    *their member variables to specs.                                                 *
    ***********************************************************************************/
    Fraction::Fraction(int num, int den)
    // Pre:  num and int have been assigned valid integers
    // Post: sets member variables of called object to num and den
    {
        assert(den != 0);
        if(num == 0){
            numerator = 0;
            denominator = 1;
        }
        else{
            if (den > 0){
                numerator = num;
                denominator = den;
            }
            else if (den < 0){
                numerator = num * (-1);
                denominator = den * (-1);
            }
        }
        this->simplify();//will simplify every object before finalizing the creation
    }

    /*********************************************************************************
     *This is an << operator overload.                                               *
    *Absolute value of fract.numerator is compared to fract.denominator to see if   *
    *fraction is proper(abs(den)<num), improper(abs(den)>num) or whole number(den=1)*
    *********************************************************************************/
    ostream &operator << (ostream &strm, const Fraction &fract)
    {
        if(fract.denominator == 1)
            strm << fract.numerator /* <<endl*/;
        else if (abs(fract.numerator) < fract.denominator)
            strm << fract.numerator << "/" << fract.denominator /* <<endl*/;
        else if(abs(fract.numerator) > fract.denominator)
            strm << fract.numerator/fract.denominator << "+" << abs(fract.numerator % fract.denominator) << "/" << fract.denominator /* << endl*/;
        return strm;
    }

    /*********************************************************************************
    *This is an >> operator overload.                                               *
    *Data from the istream is processed in certain way, depensing of the data value.*
    *The first whole number from the stream will be the numerator, after which we   *
    *check for a '/' or a '+'. If none exist, we are done processing. If '/' is the *
    *character in the stream. we will ignore it and take in the denominator, after  *
    *which we are done with the row. If there was no '/', but there was a '+', we   *
    *will  collect the next integer as temp, and we will integrate it as part of the*
    *formula to calculate the numerator. We will ignore a '/' and collect the last  *
    *integer as the denominator. Denominator and numerator are set for fract and    *
    *istream is returned.                                                           *
    *********************************************************************************/
    istream &operator >> (istream &istrm, Fraction &fract)
    {
        int num = 0,
            temp = 0,
            den = 1;
        bool usePlus = false;
        istrm >> num;
        if ((istrm.peek())=='/'){
            istrm.ignore();
            istrm >> den;
        }
        else if((istrm.peek())=='+'){
            usePlus = true;
            istrm.ignore();
            istrm >> temp;
            if ((istrm.peek())=='/'){
                istrm.ignore();
                istrm >> den;
            }
        }
        if(usePlus == true){
            if (num < 0){
                num = num * den - temp;
            }
            else{
                num = num * den + temp;
            }
        }
        istrm.ignore(100,'\n');
        fract.numerator = num;
        fract.denominator = den;
        fract.simplify();
        return istrm;
    }

    /*********************************************************************************
    *This is an + operator overload.                                                *
    *This function adds two fractions together                                      *
    *if both fractions have the same denominator, just add the numerators           *
    *to find fraction's numerator and fraction will have the same denominator       *
    *if denominators are not equal, fraction's denominator will be the result of    *
    *their denominators multiplied                                                  *
    *fraction numerator in this case will be the addition between the numerator of  *
    *self fraction multiplied by fract's denominator and fract's numerator multiplied 
    *by self's denominator;                                                         *
    *Function returns the new object fraction that represents the addition          *
    *********************************************************************************/
    Fraction operator + (const Fraction leftFract, const Fraction rightFract)
    // Pre: leftFract and rightFract have been created and initialized
    // Post: leftFract + rightFract is returned.
    {
        int num,
            den;
        if(leftFract.getDenominator() == rightFract.getDenominator()){
            num += rightFract.getNumerator();
            den = leftFract.getDenominator();
        }
        
        else{
            den = leftFract.getDenominator() * rightFract.getDenominator();
            num = leftFract.getNumerator() * rightFract.getDenominator() + rightFract.getNumerator() * leftFract.getDenominator();
        }
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }

    /*********************************************************************************
     *This is an + operator overload.                                                *
    *This function adds an integer and a fraction together by turning the integer   *
    *into a fraction and then adding them                                           *
    *if both fractions have the same denominator, just add the numerators           *
    *to find fraction's numerator and fraction will have the same denominator       *
    *if denominators are not equal, fraction's denominator will be the result of    *
    *their denominators multiplied                                                  *
    *fraction numerator in this case will be the addition between the numerator of  *
    *self fraction multiplied by fract's denominator and fract's numerator multiplied 
    *by self's denominator;                                                         *
    *Function returns the new object fraction that represents the addition          *
    *********************************************************************************/
    Fraction operator + (int number, const Fraction rightFract)
    // Pre: number and rightFract have been created and initialized to valid
    // Post: whole number + rightFract is returned.
    {
        Fraction fractNumber(number);
        int num,
            den;
        if(fractNumber.getDenominator() == rightFract.getDenominator()){
            num += rightFract.getNumerator();
            den = fractNumber.getDenominator();
        }
        
        else{
            den = fractNumber.getDenominator() * rightFract.getDenominator();
            num = fractNumber.getNumerator() * rightFract.getDenominator() + rightFract.getNumerator() * fractNumber.getDenominator();
        }
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }


    /*********************************************************************************
     *This is an + operator overload.                                                *
    *This function adds a fraction and a n integer together by turning the integer  *
    *into a fraction and then adding them                                           *
    *if both fractions have the same denominator, just add the numerators           *
    *to find fraction's numerator and fraction will have the same denominator       *
    *if denominators are not equal, fraction's denominator will be the result of    *
    *their denominators multiplied                                                  *
    *fraction numerator in this case will be the addition between the numerator of  *
    *self fraction multiplied by fract's denominator and fract's numerator multiplied 
    *by self's denominator;                                                         *
    *Function returns the new object fraction that represents the addition          *
    *********************************************************************************/
    Fraction operator + (const Fraction leftFract, int number)
    // Pre: leftFract and number have been created and initialized
    // Post: leftFract + whole number is returned.
    {
        Fraction fractNumber = Fraction(number);
        int num,
            den;
        if(leftFract.getDenominator() == fractNumber.getDenominator()){
            num += fractNumber.getNumerator();
            den = leftFract.getDenominator();
        }
        
        else{
            den = leftFract.getDenominator() * fractNumber.getDenominator();
            num = leftFract.getNumerator() * fractNumber.getDenominator() + fractNumber.getNumerator() * leftFract.getDenominator();
        }
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }

    /*********************************************************************************
     *This is an - operator overload.                                                *
    *This function substracts fractions                                             *
    *if both fractions have the same denominator, just substract the numerators     *
    *to find fraction's numerator and fraction will have the same denominator       *
    *if denominators are not equal, fraction's denominator will be the result of    *
    *their denominators multiplied                                                  *
    *to find numerator, substract the product of rightFract's numerator and         *
    *leftFract's denominator out of the product of self's  numerator and fract's    *
    *denominator                                                                    *
    *********************************************************************************/
    Fraction operator - (const Fraction leftFract, const Fraction rightFract)
    // Pre: leftFract and rightFract have been created and initialized
    // Post: leftFract - rightFract is returned.
    {
        int num,
            den;
        if(leftFract.getDenominator() == rightFract.getDenominator()){
            num = leftFract.getNumerator() - rightFract.getNumerator();
            den = leftFract.getDenominator();
        }
        else{
            den = leftFract.getDenominator() * rightFract.getDenominator();
            num = leftFract.numerator * rightFract.getDenominator() - rightFract.getNumerator() * leftFract.getDenominator();
        }
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }


    /*********************************************************************************
     *This is an - operator overload.                                                *
    *This function substracts a fraction from a whole number by turning the whole   *
    *number into a fraction.                                                        *
    *if both fractions have the same denominator, just substract the numerators     *
    *to find fraction's numerator and fraction will have the same denominator       *
    *if denominators are not equal, fraction's denominator will be the result of    *
    *their denominators multiplied                                                  *
    *to find numerator, substract the product of rightFract's numerator and         *
    *leftFract's denominator out of the product of self's  numerator and fract's    *
    *denominator                                                                    *
    *********************************************************************************/
    Fraction operator - (int number, const Fraction rightFract)
    // Pre: number and rightFract have been created and initialized
    // Post: number - rightFract is returned.
    {
        Fraction fractNum = Fraction(number);
        int num,
            den;
        if(fractNum.getDenominator() == rightFract.getDenominator()){
            num = fractNum.getNumerator() - rightFract.getNumerator();
            den = fractNum.getDenominator();
        }
        else{
            den = fractNum.getDenominator() * rightFract.getDenominator();
            num = fractNum.getNumerator() * rightFract.getDenominator() - rightFract.getNumerator() * fractNum.getDenominator();
        }
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }


    /*********************************************************************************
     *This is an - operator overload.                                                *
    *This function substracts a whole number from a fraction by turning the whole   *
    *number into a fraction.                                                        *
    *if both fractions have the same denominator, just substract the numerators     *
    *to find fraction's numerator and fraction will have the same denominator       *
    *if denominators are not equal, fraction's denominator will be the result of    *
    *their denominators multiplied                                                  *
    *to find numerator, substract the product of rightFract's numerator and         *
    *leftFract's denominator out of the product of self's  numerator and fract's    *
    *denominator                                                                    *
    *********************************************************************************/
    Fraction operator - (const Fraction leftFract, int number)
    // Pre: leftFract and number have been created and initialized
    // Post: leftFract - number is returned.
    {
        Fraction fractNum = Fraction(number);
        int num,
            den;
        if(leftFract.getDenominator() == fractNum.getDenominator()){
            num = leftFract.getNumerator() - fractNum.getNumerator();
            den = leftFract.getDenominator();
        }
        else{
            den = leftFract.getDenominator() * fractNum.getDenominator();
            num = leftFract.numerator * fractNum.getDenominator() - fractNum.getNumerator() * leftFract.getDenominator();
        }
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }

    /************************************************************************
     *This is an * operator overload.                                       *
    *This function multiplies two fractions and returns a fraction object  *
    *that is the result                                                    *
    *The two fractions numerators are multiplied together to get the new   *
    *objects numerator                                                     *
    *The two fractions denominators are multiplied together to get the new *
    *objects denominator                                                   *
    ************************************************************************/
    Fraction operator * (const Fraction leftFract, const Fraction rightFract)
    // Pre: leftFract and rightFract have been created and initialized
    // Post: leftFract - rightFract is returned.
    {
        int num,
            den;
        num = leftFract.getNumerator() * rightFract.getNumerator();
        den = leftFract.getDenominator() * rightFract.getDenominator();
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }


    /************************************************************************
     *This is an * operator overload.                                       *
    *This function multiplies one whole number and a fraction. The whole   *
    *number is turned into a fraction. The function returns a fraction     *
    *object that is the result  of the multiplication                      *
    *The two fractions numerators are multiplied together to get the new   *
    *objects numerator                                                     *
    *The two fractions denominators are multiplied together to get the new *
    *objects denominator                                                   *
    ************************************************************************/
    Fraction operator * (int number, const Fraction rightFract)
    // Pre: number and rightFract have been created and initialized
    // Post: fractnum - rightFract is returned.
    {
        Fraction fractNum = Fraction(number);
        int num,
            den;
        num = fractNum.getNumerator() * rightFract.getNumerator();
        den = fractNum.getDenominator() * rightFract.getDenominator();
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }


    /************************************************************************
     *This is an * operator overload.                                       *
    *This function multiplies one fraction and one whole number. The whole *
    *number is turned into a fraction. The function returns a fraction     *
    *object that is the result  of the multiplication                      *
    *The two fractions numerators are multiplied together to get the new   *
    *objects numerator                                                     *
    *The two fractions denominators are multiplied together to get the new *
    *objects denominator                                                   *
    ************************************************************************/
    Fraction operator * (const Fraction leftFract, int number)
    // Pre: leftFract and number have been created and initialized
    // Post: leftFract - number is returned.
    {
        Fraction fractNum = Fraction(number);
        int num,
            den;
        num = leftFract.getNumerator() * fractNum.getNumerator();
        den = leftFract.getDenominator() * fractNum.getDenominator();
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }

    /************************************************************************
     *This is an / operator overload.                                       *
    *This function divides two fractions and returns a fraction object     *
    *that is the result                                                    *
    *The leftFract's numerator is multiplied with rightFract's denominator *
    *to get the new objects numerator                                      *
    *The leftFract's denominator is multiplied with rightFract's numerator *
    *to get the new objects denominator                                    *
    ************************************************************************/
    Fraction operator / (const Fraction leftFract, const Fraction rightFract)
    // Pre: leftFract and rightFract have been created and initialized
    // Post: leftFract / rightFract is returned.
    {
        int num,
            den;
        num = leftFract.getNumerator() * rightFract.getDenominator();
        den = leftFract.getDenominator() * rightFract.getNumerator();
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }

    /************************************************************************
     *This is an / operator overload.                                       *
    *This function divides a whole number by a fraction. The whole         *
    *number is taken in as a fraction object. The two objects are divided  *
    *and the function returns the fraction result                          *
    *The whole number's fraction numerator is multiplied with rightFract's *
    *denominator to get the new objects numerator                          *
    *The whole number's fraction denominator is multiplied with rightFract's 
    *numerator to get the new objects denominator                          *
    ************************************************************************/
    Fraction operator / (int number, const Fraction rightFract)
    // Pre: number and rightFract have been created and initialized
    // Post: number / rightFract is returned.
    {
        Fraction fractNum = Fraction(number);
        int num,
            den;
        num = fractNum.getNumerator() * rightFract.getDenominator();
        den = fractNum.getDenominator() * rightFract.getNumerator();
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }


    /************************************************************************
     *This is an / operator overload.                                       *
    *This function divides a fractions with a whole number. and returns a  *
    *fraction object. The whole number is taken in as a fraction object.   *
    *The objects are divided and the function returns the fraction result  *
    *leftFract's numerator is multiplied with whole number's denominator   *
    *to get the new objects numerator, leftFract's denominator is multiplied
    *with whole number's numerator to get the new objects denominator      *
    ************************************************************************/
    Fraction operator / (const Fraction leftFract, int number)
    // Pre: leftFract and number have been created and initialized
    // Post: leftFract / number is returned.
    {
        Fraction fractNum = Fraction(number);
        int num,
            den;
        num = leftFract.getNumerator() * fractNum.getDenominator();
        den = leftFract.getDenominator() * fractNum.getNumerator();
        Fraction fraction = Fraction(num,den);
        //fraction.simplify();
        return fraction;
    }

    /*********************************************************************************
     *This is an += operator overload.                                               *
    *This function adds two fractions together. self and rightFract.                *
    *Function piggy backs off the + operator overload function.                     *
    *Function returns *this after the addition .                                    *
    *********************************************************************************/
    Fraction Fraction::operator += (const Fraction rightFract)
    // Pre: self and rightFract have been created and initialized
    // Post: self + rightFract is returned.
    {
        *this = *this + rightFract;
        this->simplify();
        return *this;
    }

    /*********************************************************************************
     *This is an -= operator overload.                                               *
    *This function substracts two fractions. self and rightFract.                   *
    *Function piggy backs off the - operator overload function.                     *
    *Function returns *this after the substraction.                                 *
    *********************************************************************************/
    Fraction Fraction::operator -= (const Fraction rightFract)
    // Pre: leftFract and rightFract have been created and initialized
    // Post: leftFract - rightFract is returned.
    {
        *this = *this - rightFract;
        this->simplify();
        return *this;
    }


    /*********************************************************************************
     *This is an *= operator overload.                                               *
    *This function multiplies two fractions together. self and rightFract.          *
    *Function piggy backs off the * operator overload function.                     *
    *Function returns *this after the multiplication.                               *
    *********************************************************************************/
    Fraction Fraction::operator *= (const Fraction rightFract)
    // Pre: leftFract and rightFract have been created and initialized
    // Post: leftFract * rightFract is returned.
    {
        *this = *this * rightFract;
        this->simplify();
        return *this;
    }


    /*********************************************************************************
     *This is an /= operator overload.                                               *
    *This function divides two fractions together. self and rightFract.             *
    *Function piggy backs off the / operator overload function.                     *
    *Function returns *this after the division and .                                *
    *********************************************************************************/
    Fraction Fraction::operator /= (const Fraction rightFract)
    // Pre: leftFract and rightFract have been created and initialized
    // Post: leftFract / rightFract is returned.
    {
        *this = *this / rightFract;
        this->simplify();
        return *this;
    }

    /*********************************************************************************
     *This is an prefix ++ operator overload.                                        *
    *This function divides adds one to self fraction, simplifies and returns self   *
    *Function piggy backs off the + operator overload function.                     *
    *********************************************************************************/
    Fraction Fraction::operator ++ ()
    // Post: ++self is returned
    {
        *this = *this + 1;
        this->simplify();
        return *this;
    }

    /*********************************************************************************
     *This is an postfix ++ operator overload.                                       *
    *This function adds one to a fraction. Returns a copy of the fraction before    *
    *the adition happened.                                                          *
    *Function piggy backs off the + operator overload function.                     *
    *********************************************************************************/
    Fraction Fraction::operator ++ (int)
    // Post: self++ is returned.
    {
        Fraction fract(numerator, denominator);
        *this = *this + 1;
        this->simplify();
        return fract;
    }

    /*********************************************************************************
     *This is an prefix -- operator overload.                                        *
    *This function substracts 1 from a self fraction and returns the fraction.      *
    *Function piggy backs off the - operator overload function.                     *
    *********************************************************************************/
    Fraction Fraction::operator -- ()
    // Post: --self is returned
    {
        *this = *this - 1;
        this->simplify();
        return *this;
    }

    /*********************************************************************************
     *This is an postfix -- operator overload.                                       *
    *This function substracts 1 from a self fraction, makes a copy of the fraction  *
    *before the substraction operation and returns the copy.                        *
    *Function piggy backs off the - operator overload function.                     *
    *********************************************************************************/
    Fraction Fraction::operator -- (int)
    // Post: temp-- is returned
    {
        Fraction fract(numerator, denominator);
        *this = *this - 1;
        this->simplify();
        return fract;
    }

    /************************************************************************
     *This is an == operator overload.                                      *
    *This function compares two fractions and returns a true if they are and 
    *a false if they arent.                                                *
    *The two fractions are equal if leftFract's numerator multiplied with  *
    *rightFract's denominator is equal to leftFract's denominator          *
    *multiplied with leftFract's numerator                                 *
    ************************************************************************/
    bool operator == (const Fraction leftFract, const Fraction rightFract)
    //Pre: leftFract and rightFract have been created and initialized
    //Post: True or false is returned

    {
        if(leftFract.getNumerator() * rightFract.getDenominator() == leftFract.getDenominator() * rightFract.getNumerator())
            return true;
        else
            return false;
    }


    /************************************************************************
     *This is an != operator overload.                                      *
    *This function compares two fractions and returns a true if they are   *
    *different (not equal) and a false if they arent.                      *                           *
    *The two fractions are equal if leftFract's numerator multiplied with  *
    *rightFract's denominator is equal to leftFract's denominator          *
    *multiplied with leftFract's numerator                                 *
    ************************************************************************/
    bool operator != (const Fraction leftFract, const Fraction rightFract)
    //Pre: leftFract and rightFract have been created and initialized
    //Post: True or false is returned

    {
        if(leftFract.getNumerator() * rightFract.getDenominator() != leftFract.getDenominator() * rightFract.getNumerator())
            return true;
        else
            return false;
    }


    /************************************************************************
     *This is an < operator overload.                                       *
    *This function compares two fractions and returns a true if leftFract  *
    *is less than leftFract when < is used.                                *
    *If the denominators are equal, we only compare numerators, else, we   *
    *bring the denominators to be equal and then compare numerators.       *
    ************************************************************************/
    bool operator < (const Fraction leftFract, const Fraction rightFract)
    //Pre: leftFract and rightFract have been created and initialized
    //Post: True or false is returned
    {
        if(leftFract.getDenominator() == rightFract.getDenominator()){
            if(leftFract.getNumerator() < rightFract.getNumerator()){
                return true;
            }
            else{
                return false;
            }
            
        }
        else{
            if((leftFract.getNumerator() * rightFract.getDenominator()) < (rightFract.getNumerator() * leftFract.getDenominator())){
                return true;
            }
            else{
                return false;
            }
        }
    }


    /************************************************************************
     *This is an > operator overload.                                       *
    *This function compares two fractions and returns a true if leftFract  *
    *is greater than leftFract when > is used.                             *
    *If the denominators are equal, we only compare numerators, else, we   *
    *bring the denominators to be equal and then compare numerators.       *
    ************************************************************************/
    bool operator > (const Fraction leftFract, const Fraction rightFract)
    //Pre: leftFract and rightFract have been created and initialized
    //Post: True or false is returned
    {
        if(leftFract.getDenominator() == rightFract.getDenominator()){
            if(leftFract.getNumerator() > rightFract.getNumerator()){
                return true;
            }
            else{
                return false;
            }
            
        }
        else{
            if((leftFract.getNumerator() * rightFract.getDenominator()) > (rightFract.getNumerator() * leftFract.getDenominator())){
                return true;
            }
            else{
                return false;
            }
        }
    }


    /************************************************************************
     *This is an >= operator overload.                                      *
    *This function compares two fractions and returns a true if leftFract  *
    *is greater or equal than leftFract when >= is used.                   *
    *If the denominators are equal, we only compare numerators, else, we   *
    *bring the denominators to be equal and then compare numerators.       *
    ************************************************************************/
    bool operator >= (const Fraction leftFract, const Fraction rightFract)
    //Pre: leftFract and rightFract have been created and initialized
    //Post: True or false is returned
    {
        if(leftFract.getDenominator() == rightFract.getDenominator()){
            if(leftFract.getNumerator() >= rightFract.getNumerator()){
                return true;
            }
            else{
                return false;
            }
            
        }
        else{
            if((leftFract.getNumerator() * rightFract.getDenominator()) >= (rightFract.getNumerator() * leftFract.getDenominator())){
                return true;
            }
            else{
                return false;
            }
        }
    }


    /************************************************************************
     *This is an <= operator overload.                                      *
    *This function compares two fractions and returns a true if leftFract  *
    *is less or equal than leftFract when <= is used.                      *
    *If the denominators are equal, we only compare numerators, else, we   *
    *bring the denominators to be equal and then compare numerators.       *
    ************************************************************************/
    bool operator <= (const Fraction leftFract, const Fraction rightFract)
    //Pre: leftFract and rightFract have been created and initialized
    //Post: True or false is returned
    {
        if(leftFract.getDenominator() == rightFract.getDenominator()){
            if(leftFract.getNumerator() <= rightFract.getNumerator()){
                return true;
            }
            else{
                return false;
            }
            
        }
        else{
            if((leftFract.getNumerator() * rightFract.getDenominator()) <= (rightFract.getNumerator() * leftFract.getDenominator())){
                return true;
            }
            else{
                return false;
            }
        }
    }

    /************************************************************************
     *This function simplifies a fraction                                   *
    *The greatest common divisor is found of the numerator and denominator *
    *and the denominator and numerator get divided by it                   *
    ************************************************************************/
    void Fraction::simplify()
    // Pre: function call
    // Post: fraction is simplified 
    {
        int simplifyby = 1;
        if(numerator > denominator){
            for(int i = 2;i <= denominator; i++ ){
                if(numerator % i == 0 && denominator % i == 0)
                simplifyby = i;
            }
        }
        else if(numerator == denominator){
            simplifyby = numerator;
        }
        else{
            for(int i = 2;i <= abs(numerator); i++ ){
                if(numerator % i == 0 && denominator % i == 0){
                    simplifyby = i;
                }
            }
        }
        numerator /= simplifyby;
        denominator /= simplifyby;
    }

    /************************************************************************
     *This function prints numerator and denominator of a fraction object in* 
    *the x/x format                                                        *
    ************************************************************************/
    void Fraction::showFraction() const
    // Pre:  Function call
    // Post: Prints console message
    {
        cout << numerator << "/" << denominator;
    /*  //use this to print without a denominator when denominator = 1;
        if(denominator == 1){
            cout << numerator;
        }
        else{
            cout << numerator << "/" << denominator;
        }
        */
    }

    /************************************************************************
     *This function assigns numerator and denominator to a new fraction     *
    object, simplifies and returns it                                      *
    ************************************************************************/
    void Fraction::getFraction()
    // Pre: Function call
    // Post: numerator and denominator are set according to cin and fract is returned
    {   
        int num, den;
        cout << "Enter values for a fraction object " << endl;
        cout << "Numerator: ";
        cin >> num;
        //
        cout << "NUM=" << num << endl;
        //
        cout << "Denominator: ";
        cin >> den;
        //
        cout << "DEN=" << den << endl;
        numerator = num;
        denominator = den;
        simplify();
    }

    //numerator getter member function
    int Fraction::getNumerator() const
    // Pre:  Function call
    // Post: Numerator of fract is returned.
    {
        return numerator;
    }

    //denominator getter member function
    int Fraction::getDenominator() const
    // Pre:  Function call
    // Post: Denominator of fract is returned.
    {
        return denominator;
    }
}