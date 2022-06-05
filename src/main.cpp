#include <iostream>
#include <gtest/gtest.h>
#include<numeric>


#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"



int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        //auto mamad{q3::gather_flights("/usr/src/app/resources/flights.txt")};
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