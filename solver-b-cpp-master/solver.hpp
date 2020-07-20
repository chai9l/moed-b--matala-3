#ifndef SOLVER_A_MASTER_SOLVER_HPP
#define SOLVER_A_MASTER_SOLVER_HPP

#include <iostream>

using namespace std;

#include <complex>

namespace solver {

    class RealVariable {
    private:
        double a, b , c;
        // ax^2 + bx + c

    public:
        //-------------------------------------
        //Init list - initial the variables
        RealVariable(double a, double b, double c);
        RealVariable() : a(0), b(1), c(0) {}

        const double & get_a () const{
            return a;
        }
        const double & get_b () const{
            return b;
        }
        const double & get_c () const{
            return c;
        }

        //-------------------------------------
        // Friend Binary Operators Functions
        friend RealVariable operator-(const RealVariable &x, double c); //x-c
        friend RealVariable operator-(const RealVariable &x, RealVariable c); //x-x
        friend RealVariable operator-( double c, const RealVariable &x); //c-x

        friend RealVariable operator*(const RealVariable &x, double c); //x*c
        friend RealVariable operator*(const RealVariable &x, RealVariable c); //x*x
        friend RealVariable operator*( double c, const RealVariable &x); //c*x

        friend RealVariable operator==(const RealVariable &x,  double c); // x == c
        friend RealVariable operator==(const RealVariable &x, const RealVariable &c); // x == x
        friend RealVariable operator==( double c, RealVariable x); // c == x

        friend RealVariable operator^(const RealVariable &x, double c); // x^c
        friend RealVariable operator^(const RealVariable &x, const RealVariable &c); // x^x
        friend RealVariable operator^(double c, const RealVariable &x); // c^x

        friend RealVariable operator+(const RealVariable &x, double c); // x+c
        friend RealVariable operator+(const RealVariable &x, const RealVariable &c); // x+x
        friend RealVariable operator+(double c, const RealVariable &x); // c+x

        friend RealVariable operator/(const RealVariable &x, double c); // x/c
        friend RealVariable operator/(const RealVariable &x, const RealVariable &c); // x/x
        friend RealVariable operator/(double c, const RealVariable &x); // c/x
        //-------------------------------------
    }; //End of class RealVariable

    double solve(const RealVariable &Real);

    // a + real*image
    class ComplexVariable {
    private:
        complex<double> _imagA, _imagB, _real;
    public:
        //-------------------------------------
        //Init list - initial the variables
        ComplexVariable(complex<double> _imagA ,complex<double> _imagB, complex<double> _real);
        ComplexVariable() : _imagA(0),_imagB(1,0),_real(0) {}

        const complex<double> & get_real () const{
            return _real;
        }
        const complex<double> & get_imagA () const{
            return _imagA;
        }
        const complex<double> & get_imagB () const{
            return _imagB;
        }

        //-------------------------------------
        // Friend Binary Operators Functions
        friend ComplexVariable operator-(const ComplexVariable &x, double c); //x-c
        friend ComplexVariable operator-(const ComplexVariable &x,const ComplexVariable &c); //x-x
        friend ComplexVariable operator-(double c,const ComplexVariable &x); //c-x
        friend ComplexVariable operator-(const ComplexVariable &x,  std::complex<double> i); //x-i
        friend ComplexVariable operator-(std::complex<double> i,const ComplexVariable &x); //i-x

        friend ComplexVariable operator*(const ComplexVariable &x, double c); //x*c
        friend ComplexVariable operator*(const ComplexVariable &x,const ComplexVariable &c); //x*x
        friend ComplexVariable operator*(double c,const ComplexVariable &x); //c*x
        friend ComplexVariable operator*(const ComplexVariable &x, std::complex<double> i); //x*i
        friend ComplexVariable operator*(std::complex<double> i,const ComplexVariable &x); //i*x




        friend ComplexVariable operator==(const ComplexVariable &x, double c); // x == c
        friend ComplexVariable operator==(const ComplexVariable &x, const ComplexVariable &c); // x == x
        friend ComplexVariable operator==(double c,const ComplexVariable &x); // c == x

        friend ComplexVariable operator^(const ComplexVariable &x, double c); // x^c

        friend ComplexVariable operator+(const ComplexVariable &x, double c); // x+c
        friend ComplexVariable operator+(const ComplexVariable &x, const ComplexVariable &c); // x+x
        friend ComplexVariable operator+(double c, const ComplexVariable &x); // c+x
        friend ComplexVariable operator+(const ComplexVariable &x, std::complex<double> i); //x+i
        friend ComplexVariable operator+(std::complex<double> i,const ComplexVariable &x); //i+x

        friend ComplexVariable operator/(const ComplexVariable &x, double c); // x/c
        friend ComplexVariable operator/(const ComplexVariable &x, const ComplexVariable &c); // x/x
        friend ComplexVariable operator/(double c,const ComplexVariable &x); // c/x
        //-------------------------------------
    };

    complex<double> solve(const ComplexVariable &c);
};
#endif //SOLVER_A_MASTER_SOLVER_HPP
