#include <iostream>
#include <cstring>

#include "state.hpp"

constexpr unsigned long long iterations = 2000000;

int main() {

    modeling::state_machine state_machine;

    unsigned long long state_counter[12];
    unsigned long long common_length = 0;
    std::memset(&state_counter, 0, sizeof(unsigned long long) * 12);


    for(unsigned long long i = 0; i < iterations; ++i) {
        auto new_state = state_machine.mutate();
        state_counter[new_state] += 1;
        common_length += modeling::state_length[new_state];
    }

    double check = 0.0;
    for(int i = 0; i < 12; ++i) {
        check += (double)state_counter[i] / iterations;
        std::cout << "S" << i + 1 << " probability: " << (double)state_counter[i] / iterations << std::endl;
    }

    std::cout << "Summary probability check:" << check << std::endl;
    std::cout << "average size: " << (double)common_length / iterations << std::endl;

    return 0;
}