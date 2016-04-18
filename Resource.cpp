//
// Created by nando2496 on 4/5/2016.
//
#include "Resource.h"

namespace Gaming {

    const double Resource::RESOURCE_SPOIL_FACTOR = 1.2;

    Resource::Resource(const Game &g, const Position &p, double capacity) : Piece(g, p) {

    }

    Resource::~Resource() {

    }

    double Resource::consume() {
        double ret = __capacity;
        __capacity = 0;
        return ret;
    }

    void Resource::age() {
            __capacity -= RESOURCE_SPOIL_FACTOR;
        if(__capacity <= 0) finish();
    }

    ActionType Resource::takeTurn(const Surroundings &s) const {
        return ActionType::STAY;
    }

    Piece &Resource::operator*(Piece &other) {

    }

    Piece &Resource::interact(Agent *) {
        return *this;
    }

    Piece &Resource::interact(Resource *) { // no interactions with resource
        return *this;
    }
}
