#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>


using namespace std;


std::ofstream ofile;

double f(double x);

int main(int argc, char*argv[]){
    double best = 1000;
    int i_best = 0;
    for (long int i = 1; i<1e10; i *= 10){
        //int i = 1000;  // number of mesh points
        double x = sqrt(2);   // reading x value
        double h = 1.0/((double) i);    // step size
        double derivative_forward_euler = (f(x+h)-f(x))/h;
        double derivative_3points = (f(x+h) - f(x-h))/(2*h);
        double TotalError_euler = fabs(derivative_forward_euler-(1.0/3));
        double TotalError_3points = fabs(derivative_3points-(1.0/3));


        if (TotalError_euler< best){
            best = TotalError_euler;
            i_best = i;
        }

    }
    std::cout << best<< std::endl;
    std::cout << i_best << std::endl;
    return 0;
}

double f(double x){
    return atan(x);
}
