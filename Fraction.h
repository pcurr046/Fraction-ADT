//Patricia Curry
//4/17/2020
//CS10B - Sujan Sarkar
//Project 2
//File: Fraction.h

/*******************************************************************************************
 * This is the specification file for Fraction class                                       *
 * CLASS INVARIANT                                                                         *
 * There are two data members used to represent the denominator and numerator for each     *
 * instance of a Fraction class object.                                                    *
 * The member functions are operations on fraction objects that are negative, improper     *
 * (larger numerator than denominator), or whole numbers (denominator of 1).               *
 *                                                                                         *
 * public:                                                                                 *
 *                                                                                         *
 *      void showFraction() const;                                                         *
 *      // Post: prints member variables in "x","x/x" or "x+x/x" format                    *
 *                                                                                         *
 *      //CONSTRUCTOR:                                                                     *
 *      Fraction(int num=0, int den=1);                                                    *
 *      // parametized && default constructor -initializes to specs                        *
 *      // sets numerator and denominator;                                                 *
 *                                                                                         *
 *      //GETTER FUNCTIONS FOR PRIVATE DATA MEMBERS                                        *
 *      int getNumerator() const;                                                          *
 *      // Post: Numerator is returned.                                                    *
 *      int getDenominator() const;                                                        *
 *      // Post: Denominator is returned.                                                  *
 *                                                                                         *
 *      //Member functions:                                                                *
 *      Fraction operator += (const Fraction rightFract);                                  *
 *      // Post: Self fraction + rightFract is returned                                    *
 *      Fraction operator -= (const Fraction rightFract);                                  *
 *      // Post: Self fraction - rightFract is returned                                    *
 *      Fraction operator *= (const Fraction rightFract);                                  *
 *      // Post: Self fraction * rightFract is returned                                    *
 *      Fraction operator /= (const Fraction rightFract);                                  *
 *      // Post: Self fraction / rightFract is returned                                    *
 *      Fraction operator ++ ();                                                           *
 *      // Post: Self fraction + 1 is returned                                             *
 *      Fraction operator ++ (int);                                                        *
 *      // Post: copy of initial self fraction is returned, 1 is added to self fraction    *
 *      Fraction operator -- ();                                                           *
 *      // Post: Self fraction - 1 is returned                                             *
 *      Fraction operator -- (int);                                                        *
 *      // Post: copy of initial self fraction is returned, 1 is substr. from self fraction*
 *      friend std::ostream &operator << (std::ostream &strm, const Fraction &fract);      *
 *      //allows outputting the object on console or file with the help of "<<"            *
 *      friend std::istream &operator >> (std::istream &istrm, Fraction &fract);           *
 *      //allows input processing of objects from console or file with the help of ">>"    *
 *      friend bool operator < (const Fraction leftFract, const Fraction rightFract);      *
 *      //Post: leftFract < rightFract is returned T/F                                     *                          
 *      friend bool operator <= (const Fraction leftFract, const Fraction rightFract);     *
 *      //Post: leftFract <= rightFract is returned T/F                                    *       
 *      friend bool operator > (const Fraction leftFract, const Fraction rightFract);      *
 *      //Post: leftFract > rightFract is returned T/F                                     *       
 *      friend bool operator >= (const Fraction leftFract, const Fraction rightFract);     *
 *      //Post: leftFract >= rightFract is returned T/F                                    *       
 *      friend bool operator == (const Fraction leftFract, const Fraction rightFract);     *
 *      //Post: leftFract == rightFract is returned T/F                                    *       
 *      friend bool operator != (const Fraction leftFract, const Fraction rightFract);     *
 *      //Post: leftFract != rightFract is returned T/F                                    *       
 *      friend Fraction operator + (const Fraction leftFract, const Fraction rightFract);  *
 *      //Post: leftFract + rightFract is returned                                         *       
 *      friend Fraction operator + (int number, const Fraction rightFract);                *
 *      //Post: number + rightFract is returned                                            *       
 *      friend Fraction operator + (const Fraction leftFract, int number);                 *
 *      //Post: leftFract + number is returned                                             *       
 *      friend Fraction operator - (const Fraction leftFract, const Fraction rightFract);  *
 *      //Post: leftFract - rightFract is returned                                         *       
 *      friend Fraction operator - (int number, const Fraction rightFract);                *
 *      //Post: number - rightFract is returned                                            *       
 *      friend Fraction operator - (const Fraction leftFract, int number);                 *
 *      //Post: leftFract - number is returned                                             *       
 *      friend Fraction operator * (const Fraction leftFract, const Fraction rightFract);  *
 *      //Post: leftFract * rightFract is returned                                         *       
 *      friend Fraction operator * (int number, const Fraction rightFract);                *
 *      //Post: number * rightFract is returned                                            *       
 *      friend Fraction operator * (const Fraction leftFract, int number);                 *
 *      //Post: leftFract * number is returned                                             *       
 *      friend Fraction operator / (const Fraction leftFract, const Fraction rightFract);  *
 *      //Post: leftFract / rightFract is returned                                         *       
 *      friend Fraction operator / (int number, const Fraction rightFract);                *
 *      //Post: number / rightFract is returned                                            *       
 *      friend Fraction operator / (const Fraction leftFract, int number);                 *
 *      //Post: leftFract / number is returned                                             *       
 *                                                                                         *
 *  private:                                                                               *
 *                                                                                         *
 *      void simplify();                                                                   *
 *      // Post: simplifies numerator and denominator                                      *
 *                                                                                         *
 *      int numerator;                                                                     *
 *      int denominator;                                                                   *
 *******************************************************************************************/

#ifndef FRACTION_H //include guard
#define FRACTION_H
namespace cs10b_fraction{//this declares the namespace 
                         //Fraction class specification block
    class Fraction
    {
        public:
  
            void showFraction() const;
            Fraction(int num=0, int den=1);
            void getFraction();
            int getNumerator() const;
            int getDenominator() const;
            friend std::ostream &operator << (std::ostream &strm, const Fraction &fract);
            friend std::istream &operator >> (std::istream &istrm, Fraction &fract);
            friend bool operator < (const Fraction leftFract, const Fraction rightFract);
            friend bool operator <= (const Fraction leftFract, const Fraction rightFract);
            friend bool operator > (const Fraction leftFract, const Fraction rightFract);
            friend bool operator >= (const Fraction leftFract, const Fraction rightFract);
            friend bool operator == (const Fraction leftFract, const Fraction rightFract);
            friend bool operator != (const Fraction leftFract, const Fraction rightFract);
            friend Fraction operator + (const Fraction leftFract, const Fraction rightFract);
            friend Fraction operator + (int number, const Fraction rightFract);
            friend Fraction operator + (const Fraction leftFract, int number);
            friend Fraction operator - (const Fraction leftFract, const Fraction rightFract);
            friend Fraction operator - (int number, const Fraction rightFract);
            friend Fraction operator - (const Fraction leftFract, int number);
            friend Fraction operator * (const Fraction leftFract, const Fraction rightFract);
            friend Fraction operator * (int number, const Fraction rightFract);
            friend Fraction operator * (const Fraction leftFract, int number);
            friend Fraction operator / (const Fraction leftFract, const Fraction rightFract);
            friend Fraction operator / (int number, const Fraction rightFract);
            friend Fraction operator / (const Fraction leftFract, int number);
            Fraction operator += (const Fraction rightFract);
            Fraction operator -= (const Fraction rightFract);
            Fraction operator *= (const Fraction rightFract);
            Fraction operator /= (const Fraction rightFract);
            Fraction operator ++ ();
            Fraction operator ++ (int);
            Fraction operator -- ();
            Fraction operator -- (int);
            



        private:

            void simplify();
            int numerator;
            int denominator;
    };
}//this closes the namespace
#endif

/*Output:

Fraction class (ADT) client program to test CLASS INVARIANT
There are two data members used to represent the denominator and numerator
for each instance of a Fraction class object class.
The client code provides an interface to test correct operations on fraction  
objects that are negative, improper (larger numerator than denominator), 
or whole numbers (denominator of 1).
Here is a list test type and order in which the tests will be conducted
1. BasicTest
2. RelationTest
3. BinaryMathTest
4. MathAssignTest

***********************************************************************
* Basic Test: Testing member constructor, simplify() and nonmember    *
* friend ostream << operator for basic Fraction object creation &     *
* printing(Fractions should be in reduced form, and as mixed numbers.)*
***********************************************************************
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

***********************************************************************
* Basic Test: Testing simplify() and nonmember friend istream >> and  *
* ostream << operators for reading and display of Fraction objects    *
* from data file                                                      *
***********************************************************************
Enter file name with fraction data to read: frac_data.txt
Read Fraction = -1/3
Read Fraction = 1/2
Read Fraction = 3/4
Read Fraction = -4/5
Read Fraction = 6
Read Fraction = 5
Read Fraction = -8
Read Fraction = 1+2/5
Read Fraction = -16+2/3
Read Fraction = 1+1/4
Read Fraction = 2
Read Fraction = -4+1/4
Read Fraction = -10+5/6

***********************************************************************
* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *
*  ==, != relational operators between Fractions                      *
***********************************************************************
Comparing 1/2 to -1/2
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing -1/2 to 1/2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing 1/2 to 1/10
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing 1/10 to 0
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing 0 to 0
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false

***********************************************************************
* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *
* ==, != relations between Fractions and integers                     *
***********************************************************************
Comparing -1/2 to 2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing -3 to 1/4
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true

***********************************************************************
* BinaryMathTest: Testing nonmember friend binary arithmetic +, -, *, *
* / operators between Fractions                                       *
***********************************************************************
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

***********************************************************************
* BinaryMathTest: Testing nonmember friend binary arithmetic +, -, *, *
* / operators between Fractions and integers                          *
***********************************************************************
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

***********************************************************************
* MathAssignTest: Testing member shorthand arithmetic assignment +=,  *
* -=, *=, /= operators on Fractions                                   *
***********************************************************************
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

***********************************************************************
* MathAssignTest: Testing member shorthand arithmetic assignment +=,  *
* -=, *=, /= operators using integers                                 *
***********************************************************************
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

***********************************************************************
* MathAssignTest: Testing member increment/decrement prefix and       *
* postfix operators                                                   *
***********************************************************************
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
*/