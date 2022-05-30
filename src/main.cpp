#include <iostream>
#include <gtest/gtest.h>


// #include "q1.h"
// #include "q2.h"
// #include "q3.h"
// #include "q4.h"


double power(double x) { return x*x ;}

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        // std::vector<q2::Patient> mamad{q2::read_file("/usr/src/app/resources/lung_cancer.csv")};
        // std::cout << mamad[0].name << std::endl;
        // q2::sort(mamad);
        // std::cout << mamad[0].name << std::endl;


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