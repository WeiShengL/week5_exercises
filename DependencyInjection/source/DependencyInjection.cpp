#include <iostream>
#include "DiscreteFunction.h"
#include <vector>

int main()
{
    std::vector<double> ys(21);
    double delta_x = 1.0 / 20;
    for(size_t i = 0; i < ys.size(); i++)
    {
        double x = delta_x * i;
        ys[i] = x*x;
    }   
    std::unique_ptr<AbstractIntegrator> myTrapeziumIntegrator = std::make_unique<TrapeziumIntegrator>();
    std::unique_ptr<AbstractIntegrator> mySimpsonIntegrator = std::make_unique<SimpsonIntegrator>();
    DiscreteFunction DF(ys, 0, 1, mySimpsonIntegrator);

    std::cout << DF.integrate() << std::endl;

    return 0;
}