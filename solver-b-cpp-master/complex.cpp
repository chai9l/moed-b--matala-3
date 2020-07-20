#include "solver.hpp"
#include <complex>
#include <stdexcept>

using namespace solver;

//-------------------------------------
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++ COMPLEX NUMBERS +++++++++++++++++++++++++++++++++++++++++++++++
//Constructor
ComplexVariable::ComplexVariable(std::complex<double> _imagA,std::complex<double> _imagB,std::complex<double> _real)
{
    this->_real = complex<double>(_real);
    this->_imagA = complex<double>(_imagA);
    this->_imagB = complex<double>(_imagB);
}
// Minus Operator
ComplexVariable solver::operator-(const ComplexVariable& x, double c){ //x-c
return ComplexVariable(x.get_imagA(),x.get_imagB(),x.get_real()-c);
}
ComplexVariable solver::operator-(const ComplexVariable& x,const ComplexVariable& c){ //x-x
    return ComplexVariable(x.get_imagA() - c.get_imagA() , x.get_imagB() - c.get_imagB(),x.get_real() - c.get_real());
}
ComplexVariable solver::operator-(double c,const  ComplexVariable& x ){ // c-x
return c-x;
}
ComplexVariable solver::operator-(const ComplexVariable &x,  std::complex<double> i) {
    return ComplexVariable(x.get_imagA(),x.get_imagB(),x.get_real()-i);

}
ComplexVariable solver::operator-( std::complex<double> i, const ComplexVariable &x) {
    return i-x;
}
//-------------------------------------
// Equal Operator
ComplexVariable solver::operator==(const ComplexVariable& x, double c){ // x == c
return x-c;
}
ComplexVariable solver::operator==(const ComplexVariable& x,const ComplexVariable& c){ // x == x
return x-c;
}
ComplexVariable solver::operator==(double c,const ComplexVariable& x){ // c == x
return c-x;
}


//-------------------------------------
// Multiply Operator
ComplexVariable solver::operator*(const ComplexVariable& x, double c){ // x*c
    return ComplexVariable(x.get_imagA()*c, x.get_imagB()*c, x.get_real()*c);
}
ComplexVariable solver::operator*(const ComplexVariable& x,const ComplexVariable& y){ // x*x
    return ComplexVariable(x.get_imagA() * y.get_imagA(), x.get_imagB() * y.get_imagB(), x.get_real() * y.get_real());
}
ComplexVariable solver::operator*(double c,const  ComplexVariable& x){ // c*x
return ComplexVariable(x.get_imagA()*c, x.get_imagB()*c, x.get_real()*c);
}
ComplexVariable solver::operator*(const ComplexVariable &x, std::complex<double> i){ // x*i
    return ComplexVariable(x.get_imagA()*i, x.get_imagB()*i, x.get_real()*i);
}
ComplexVariable solver::operator*(std::complex<double> i,const ComplexVariable &x){ // i*x
    return ComplexVariable(x.get_imagA()*i, x.get_imagB()*i, x.get_real()*i);
}
//-------------------------------------
// Exponent
ComplexVariable solver::operator^(const ComplexVariable& x, double c){ //x^c
    if(c == 0) {
        throw runtime_error {"There is no solution! "};
    }
    else if (c == 1) {
        return x;
    }
    else if (c == 2) {
        return ComplexVariable(1, 0, 0); // no needed
    }
    else {
        throw runtime_error {""};
    }
}
//-------------------------------------
// Addition
ComplexVariable solver::operator+(const ComplexVariable& x, double c){ //x+c
    return ComplexVariable(x.get_imagA(), x.get_imagB(), x.get_real() + c);
}
ComplexVariable solver::operator+(const ComplexVariable& x,const  ComplexVariable& c){ // x+x
    return ComplexVariable(x.get_imagA() + c.get_imagA(), x.get_imagB() + c.get_imagB(), x.get_real() + c.get_real());
}
ComplexVariable solver::operator+(double c, const ComplexVariable& x){ // c+x
    return ComplexVariable(x.get_imagA(), x.get_imagB(), x.get_real() + c);
}
ComplexVariable solver::operator+(const ComplexVariable &x, std::complex<double> i){
    return ComplexVariable(x.get_imagA(), x.get_imagB(), x.get_real() + i);
}
ComplexVariable solver::operator+(std::complex<double> i,const ComplexVariable &x){
    return ComplexVariable(x.get_imagA(), x.get_imagB(), x.get_real() + i);
}


//-------------------------------------
// Divide
ComplexVariable solver::operator/( const ComplexVariable& x, double c){ //x/c
    if(c == 0){
        throw runtime_error("infinite solution");
    }
    return ComplexVariable(x.get_imagA() / c,x.get_imagB() / c , x.get_real() / c);
}
ComplexVariable solver::operator/(const ComplexVariable& x,  const ComplexVariable& c){ // x/x
    return ComplexVariable(x.get_imagA() / c.get_imagA() ,x.get_imagB() / c.get_imagB() , x.get_real() / c.get_real());
}
ComplexVariable solver::operator/(double c,const  ComplexVariable& x){ // c/x
    return ComplexVariable(c/x.get_imagA(),c/x.get_imagB(),c/x.get_real());
}


//-------------------------------------
// Solve Global Function
std::complex<double> solver::solve(const ComplexVariable& x){
    cout<< " getimagA: "<<x.get_imagA() << " getimagB: "<<x.get_imagB()<< "getreal: " << x.get_real() <<endl;


            if(x.get_imagA() == std::complex<double>(0,0)
                    && x.get_imagB() == std::complex<double>(0,0)
                    && x.get_real() == std::complex<double>(0,0)) {
                throw runtime_error("infinite solution");
            }

            if(x.get_imagA() == complex<double>(0,0) && x.get_imagB() != complex<double>(0,0)) {
                return x.get_real() / -x.get_imagB();
            }
            if(x.get_imagA() == complex<double>(0,0) && x.get_imagB() == complex<double>(0,0)) {
                throw runtime_error("infinite solution");
            }
                // (-b (+-) sqrt(b^2 -4ac) ) / 2a
                return (-x.get_imagB() - sqrt(x.get_imagB() * x.get_imagB() - 4.0 * x.get_imagA()*x.get_real()) ) / (2.0*x.get_imagA());
}
//-------------------------------------