//
// Created by nando2496 on 4/5/2016.
//
#include <sstream>
#include <iomanip>
#include "Advantage.h"

namespace Gaming {

    const char Advantage::ADVANTAGE_ID = 'D';
    const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;

    Advantage::Advantage(const Game &g, const Position &p, double capacity) : Resource(g, p, capacity) {

    }
    Advantage::~Advantage() {

    }

    void Advantage::print(std::ostream &osteam) const {
        std::string str;

        str = std::to_string(__id);


        std::stringstream ss;
        ss << Advantage::ADVANTAGE_ID;
        ss << str;

        std::getline(ss, str);

        for (int i = 0; i < str.length(); ++i) {
            osteam << str[i];
        }
    }


    double Advantage::getCapacity() const {
        return __capacity * ADVANTAGE_MULT_FACTOR;
    }

    double Advantage::consume() {
        double ret = getCapacity();
        __capacity = -1;
        finish();
        return ret;
    }

}
