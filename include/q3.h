#ifndef Q3_H
#define Q3_H

#include<iostream>
#include<queue>
#include<vector>

namespace q3
{
    struct Flight
    {
        Flight(std::string _Flight_number, size_t _duration, size_t _connections, size_t _connection_times, size_t _price)
        : flight_number{_Flight_number}
        , duration{_duration}
        , connections{_connections}
        , connection_times{_connection_times}
        , price{_price}
        {
        }
        std::string flight_number;
        size_t duration;
        size_t connections;
        size_t connection_times;
        size_t price;
    };
    
    size_t time_cal(std::string time)
    {   
        if(time.empty())
        {
            return 0;
        }

        std::regex pattern(R"((\d+)\h(\d+)?\m?)");
        std::smatch match;
        std::regex_search(time, match, pattern);
        size_t total_time{static_cast<size_t>(std::stoi(match[1])) * 60};
        std::string emp_check {match[2]};
        if(emp_check.empty())
        {
            return total_time;
        }
        else
        {
            return total_time + static_cast<size_t>(std::stoi(match[2]));
            
        }
    }

    auto comparison{[](Flight a, Flight b){return (a.duration + a.connection_times + 3 * a.price) > (b.duration + b.connection_times + 3 * b.price);}};

    std::priority_queue<Flight, std::vector<Flight>, decltype(comparison)> Flight_info{comparison};

    auto gather_flights(std::string filename)
    {
        std::ifstream file(filename);
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string txt = buffer.str();

        std::regex pattern(R"(\d+\- \w+\:(\w+)\ - \w+\:(\d+\h\d*\m*)\ - \w+\:(\d+)\ - \w+\:(\d+\h\d*\m*)\,?(\d*\h*\d*\m*)\,?(\d*\h*\d*\m*) - \w+\:(\d+))");
        std::smatch match;

        while(std::regex_search(txt, match, pattern))
        {
            
            std::string flight_number{match[1]};
            size_t duration {time_cal(match[2])};  
            size_t connections{static_cast<size_t>(std::stoi(match[3]))};
            size_t connection_times{time_cal(match[4]) + time_cal(match[5]) + time_cal(match[6])};
            size_t price{static_cast<size_t>(std::stoi(match[7]))};
            std::cout << duration << std::endl;
            std::cout << match[2] << std::endl;
            Flight_info.push(Flight{flight_number, duration, connections, connection_times, price});
            txt = match.suffix().str();
        }

        return Flight_info;
    }

}

#endif //Q3_H