#ifndef Q2_H
#define Q2_H
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<regex>


namespace q2
{
    struct Patient
    {
        std::string name;
        size_t age;
        size_t smokes;
        size_t area_q;
        size_t alkhol;
    };

    std::vector<Patient> read_file(std::string filename)
    {
        std::ifstream file("usr/src/app/resources/lung_cnacer.csv");
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string txt = buffer.str();

        std::regex pattern(R"(\w)");
        std::smatch match;

        


    }
}

#endif //Q2_H