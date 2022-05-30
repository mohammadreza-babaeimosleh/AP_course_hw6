#include <iostream>
#include <gtest/gtest.h>

#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"

double power(double x) { return x*x ;}

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        double x{2.0};
        std::cout << power(x) << std::endl;
        std::cout << q1::derivative(3 , power) << std::endl;
        std::cout << q1::gradient_descent(-5, 0.1, power) << std::endl;

    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}