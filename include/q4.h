#ifndef Q4_H
#define Q4_H
#include<numeric>

namespace q4
{
    struct Vector2D
    {
        Vector2D(double _x = 0, double _y = 0)
        :x{ _x }
        ,y{ _y }
        {
        }
        double x{};
        double y{}; 
    };

    struct Sensor
    {
        Sensor(Vector2D _pos, double _accuracy = 0)
        :pos{ _pos }
        ,accuracy{ _accuracy }
        {
        }
        Vector2D pos;
        double accuracy;    
    };

    //functions for accumulate
    double avg_cal_x(double avg, Sensor& s)
    {
        return avg + s.pos.x * s.accuracy;
    }

    double avg_cal_y(double avg, Sensor& s)
    {
        return avg + s.pos.y * s.accuracy;
    }

    Vector2D kalman_filter(std::vector<Sensor> sensors)
    {
        double accuracy_sum{ std::accumulate(sensors.begin(), sensors.end(), 0.0 , [](double ans, Sensor& s){return ans + s.accuracy;}) };
        double x_pos{ std::accumulate(sensors.begin(), sensors.end(), 0.0, avg_cal_x) / accuracy_sum };
        double y_pos{ std::accumulate(sensors.begin(), sensors.end(), 0.0, avg_cal_y) / accuracy_sum };

        Vector2D final_pos{ x_pos, y_pos };

        return final_pos;
    }
}

#endif //Q4_H