#pragma once 
#include <memory>
#include <vector>
#include <functional>

class AbstractIntegrator
{
    public:
    virtual double integrate(const double delta_x, const std::vector<double> &ys) = 0;
};


class SimpsonIntegrator : public AbstractIntegrator
{
    public:
    SimpsonIntegrator();

    double integrate(const double delta_x, const std::vector<double> &ys);
};

class TrapeziumIntegrator : public AbstractIntegrator
{
    public:
    TrapeziumIntegrator();

    double integrate(const double delta_x, const std::vector<double> &ys);
};

class DiscreteFunction
{
    public:
    DiscreteFunction(std::vector<double> y, double x_min, double x_max);

    double integrate();

    void setIntegrator(std::unique_ptr<AbstractIntegrator> &inIntegrator);

    private:
    // std::unique_ptr<TrapeziumIntegrator> integrator;
    std::unique_ptr<AbstractIntegrator> integrator;
    std::vector<double> ys;
    double min_x;
    double max_x;
    double delta_x;
};

