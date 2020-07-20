#include "solver.hpp"
#include <complex>
using namespace solver;
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++ Real NUMBERS +++++++++++++++++++++++++++++++++++++++++++++++
//Constructor
RealVariable::RealVariable(double a ,double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}
// Minus Operator
RealVariable solver::operator-(const RealVariable& x, double c){ //x-c
    return RealVariable(x.get_a(),x.get_b(),x.get_c()-c);
}
RealVariable solver::operator-(const RealVariable& x, RealVariable c){ //x-x
    return RealVariable(x.get_a() - c.get_a() , x.get_b() - c.get_b(),x.get_c() - c.get_c());
}
RealVariable solver::operator-( double c, const RealVariable& x ){ // c-x
    return c-x;
}
//-------------------------------------
// Equal Operator
RealVariable solver::operator==(const RealVariable& x, double c){ // x == c
    return x - c;
}
RealVariable solver::operator==(const RealVariable& x, const RealVariable& c){ // x == x

    return x - c;
}
RealVariable solver::operator==( double c, RealVariable x){ // c == x

    return c-x;
}
//-------------------------------------
// Multiply Operator
RealVariable solver::operator*(const RealVariable& x, double c){ // x*c
    return RealVariable(x.get_a()*c, x.get_b()*c, x.get_c()*c);
}
RealVariable solver::operator*(const RealVariable& x, RealVariable y){ // x*x
    return RealVariable(x.get_a() * y.get_a(), x.get_b() * y.get_b(), x.get_c() * y.get_c());
}
RealVariable solver::operator*( double c, const RealVariable& x){ // c*x
    return RealVariable(x.get_a()*c, x.get_b()*c, x.get_c()*c);
}
//-------------------------------------
// Exponent
RealVariable solver::operator^(const RealVariable& x, double c) { //x^c
    if (c == 0) {
        return RealVariable(0, 0, 1);
    }
    else if (c == 1) {
        return x;
    }
    else if (c == 2) {
        return RealVariable(1, 0, 0); // no needed
    }
    else {
        return RealVariable(0,0,0);
    }
}
//-------------------------------------
// Addition
RealVariable solver::operator+(const RealVariable& x, double c){ //x+c
    return RealVariable(x.get_a(), x.get_b(), x.get_c() + c);
}
RealVariable solver::operator+(const RealVariable& x, const RealVariable& c){ // x+x
    return RealVariable(x.get_a() + c.get_a(), x.get_b() + c.get_b(), x.get_c() + c.get_c());
}
RealVariable solver::operator+(double c, const RealVariable& x){ // c+x
    return RealVariable(x.get_a(), x.get_b(), x.get_c() + c);
}
//-------------------------------------
// Divide
RealVariable solver::operator/(const RealVariable& x, double c){ //x/c
    if(c == 0)
        throw runtime_error("Cannot divide by 0");
    else
        return RealVariable(x.get_a() / c,x.get_b() / c , x.get_c() / c);
}
RealVariable solver::operator/(const RealVariable& x, const RealVariable& c){ // x/x
    if(c.get_a()+c.get_b()+c.get_c() == 0)
        throw runtime_error("Cannot divide by 0");
    else
        return RealVariable(x.get_a() / c.get_a() ,x.get_b() / c.get_b() , x.get_c() / c.get_c());
}
RealVariable solver::operator/(double c, const RealVariable& x){ // c/x
    if(x.get_a()+x.get_b()+x.get_c() == 0)
        throw runtime_error("Cannot divide by 0");
    else
        return RealVariable(c/x.get_a(),c/x.get_b(),c/x.get_c());
}
//-------------------------------------

// Solve Global Function
double solver::solve(const RealVariable& x){
    cout<<"x.get_a(): "<<x.get_a()<<" x.get_b(): "<<x.get_b()<<" x.get_c(): "<<x.get_c()<<endl;
    if(x.get_a() == 0) {
        if(x.get_b() == 0 && x.get_c()!=0)
            throw runtime_error {"infinite solution"};
        else
            return x.get_c()/-x.get_b();
    }
    else if(x.get_c() <= 0) // exponential x^2
    {
                    // (-b (+-) sqrt(b^2 -4ac) ) / 2a
        double x1 = (-x.get_b() + sqrt(x.get_b() * x.get_b() - 4 * x.get_a() * x.get_c()) ) / (2 * x.get_a());
        return x1;
    }
    else // x < 0 || 0 < c
    {
        throw runtime_error {"There is no Real solution! "};
    }
}