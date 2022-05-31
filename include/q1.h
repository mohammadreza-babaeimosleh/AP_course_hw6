#ifndef Q1_H
#define Q1_H
#include<cmath>


namespace q1
{
    template<typename T, typename Func>
    double derivative(T point, Func func)
    {
        double h{ 0.001 };
        double derivation{ (func(point + h) - func(point - h)) / (2.0 * h) };
        
        return derivation;
    }

    template<typename T , typename Func>
    double gradient_descent(T initial_value, double step_size , Func func=Func{})
    {

        double learn_rate{ step_size } , tolerance{ 0.00001 };
        T tmp{ initial_value };
        double diff{ learn_rate * derivative(tmp, func) }; 
        while (std::abs(diff) >= tolerance)
        {
            diff = learn_rate * derivative(tmp, func); 
            tmp = tmp - diff;
        }

        return tmp;
    }
}


#endif //Q1_H