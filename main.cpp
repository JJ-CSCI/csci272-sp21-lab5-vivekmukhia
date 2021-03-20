//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------
class Real
{
private :
    double real;
public:
    
    Real(double r)
    {
        real = r;
    }
    
    double GetReal() const 
    { 
        return real; 
    }
    
    Real operator*(double v)
    {
        Real obj(real * v);
        return obj;
    }
}; 


class Complex : public Real
{
private :
    double imaginary; 
public:
    
    
    Complex(double r, double i) : Real(r), imaginary(i)
    {
        
    }
    
    
    double GetImaginary() const
    {
        return imaginary;
    }

    Complex operator*(double v)
    {
        Complex obj(GetReal() * v, imaginary * v);
        return obj;
    }
}; 



class Surreal : public Complex
{
private :
    double surreal;
public:
    
    Surreal(double a, double b, double c) : Complex(a, b), surreal(c)
    {

    }
    
    double GetSurreal()
    {
        return surreal;
    } 
    
    Surreal operator*(double v)
    {
        Surreal obj(GetReal() * v, GetImaginary() * v, surreal * v);
        return obj;
    }
};


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
