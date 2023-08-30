#include "RandomEIntegerGenerator.h"

namespace Hist {

    RandomEintegerGenerator::RandomEintegerGenerator() {
        // Initialize the random number generator
        std::random_device rd;
        generator_.seed(rd());
    }

    RandomEintegerGenerator::~RandomEintegerGenerator() {}

    EInteger RandomEintegerGenerator::operator()() {
        // Generate a random integer between 0 and 4 (inclusive)
        std::uniform_int_distribution<int> distribution(0, 4);
        int randomInt = distribution(generator_);

        // Map the random integer to an EInteger value
        switch (randomInt) {
            case 0: return EInteger::Zero;
            case 1: return EInteger::One;
            case 2: return EInteger::Two;
            case 3: return EInteger::Three;
            case 4: return EInteger::Four;
            default: return EInteger::Zero; // Handle unexpected values gracefully
        }
    }

}  // namespace Hist
