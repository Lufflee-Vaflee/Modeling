#pragma once

#include <random>

#include <exception>

namespace modeling {

enum state {
    _1 = 0,     //= 2000,
    _2,      //= 1000,
    _3,      //= 2010,
    _4,      //= 1010,
    _5,      //= 2011,
    _6,      //= 1011,
    _7,      //= 1001,
    _8,      //= 2111,
    _9,      //= 1111,
    _10,     //= 2211,
    _11,     //= 1211,
    _12,     //= 0211
};

constexpr unsigned state_length[12] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2};

class state_machine {
public:
    state_machine() {
        std::srand(time(0));
    }

    static constexpr int P1 = 75;
    static constexpr int P2 = 60;

    bool first_task() {
        return (std::rand() % 100) >= P1;
    }

    bool second_task() {
        return (std::rand() % 100) >= P2;
    }


    state mutate() {
        state new_state;

        bool p1 = first_task();
        bool p2 = second_task();

        switch (m_current)
        {
        case _1:
            new_state = state::_2;
            break;
        case _2:
            new_state = state::_3;
            break;
        case _3:
            new_state = p1 ? state::_2 : state::_4;
            break;
        case _4:
            new_state = p1 ? state::_3 : state::_5;
            break;
        case _5:
            if(p1 == true) {
                new_state = p2 ? state::_2 : state::_7;
            } else {
                new_state = p2 ? state::_4 : state::_6;
            }
            break;
        case _6:
            if(p1 && p2) {
                new_state = state::_3;
            } else if(!p1 && !p2) {
                new_state = state::_8;
            } else {
                new_state = state::_5;
            }
            break;
        case _7:
            new_state = p2 ? state::_3 : state::_5;
            break;
        case _8:
            if(p1 && p2) {
                new_state = state::_4;
            } else if(!p1 && !p2) {
                new_state = state::_9;
            } else {
                new_state = state::_6;
            }
            break;
        case _9:
            if(p1 && p2) {
                new_state = state::_5;
            } else if(!p1 && !p2) {
                new_state = state::_10;
            } else {
                new_state = state::_8;
            }
            break;
        case _10:
            if(p1 && p2) {
                new_state = state::_6;
            } else if(!p1 && !p2) {
                new_state = state::_11;
            } else {
                new_state = state::_9;
            }
            break;
        case _11:
            if(p1 && p2) {
                new_state = state::_8;
            } else if(!p1 && !p2) {
                new_state = state::_12;
            } else {
                new_state = state::_10;
            }
            break;
        case _12:
            if(p1 && p2) {
                new_state = state::_8;
            } else if (!p1 && !p2) {
                new_state = state::_12;
            } else {
                new_state = state::_10;
            }
            break;
        default:
            throw "AAAAAAAAAAA";
            break;
        }

        this->m_current = new_state;
        return new_state;
    }

    state m_current = state::_1;
};

};