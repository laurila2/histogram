#include "histogram.h"
#include "RandomEIntegerGenerator.h"
#include "Log.h"

#include <iostream>
#include <memory>

int main() {
    // Create a Logger (you may need to implement the Logger class)
    std::unique_ptr<Hist::Logger> logger = std::make_unique<Hist::Logger>();

    // Create a Histogram using the Logger
    Hist::Histogram histogram(std::move(logger));

    // Create a RandomEintegerGenerator
    Hist::RandomEintegerGenerator randomGenerator;

    // Generate and add random values to the histogram
    for (int i = 0; i < 100; ++i) {
        Hist::EInteger randomValue = randomGenerator();
        histogram.add(randomValue);
    }

    // Get and display the mode, minimum, and maximum values
    Hist::EInteger mode = histogram.getMode();
    Hist::EInteger min = histogram.getMinValue();
    Hist::EInteger max = histogram.getMaxValue();

    std::cout << "Mode: " << static_cast<int>(mode) << std::endl;
    std::cout << "Minimum Value: " << static_cast<int>(min) << std::endl;
    std::cout << "Maximum Value: " << static_cast<int>(max) << std::endl;

    return 0;
}
