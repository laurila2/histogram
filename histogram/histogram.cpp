#include "histogram.h"
#include "Log.h"

#include <algorithm>

namespace Hist {

    Histogram::Histogram(std::unique_ptr<Logger> logger) : HistogramBase(std::move(logger)) {}

    Histogram::~Histogram() {}

    void Histogram::add(EInteger value) {
        // Increment the count for the given value
        data_[value]++;
    }

    EInteger Histogram::getMode() const {
        if (data_.empty()) {
          // Handle the case when the dataset is empty
          throw std::runtime_error("Error: Cannot calculate mode of an empty dataset.");
        }

        // Find the mode by iterating through the data
        EInteger mode = data_.begin()->first;
        int maxCount = data_.begin()->second;

        for(const auto& pair : data_) {
            if (pair.second > maxCount) {
                mode = pair.first;
                maxCount = pair.second;
            }
        }

        return mode;
    }

    EInteger Histogram::getMinValue() const {
        if (data_.empty()) {
            // Handle the case when the dataset is empty
            throw std::runtime_error("Error: Cannot find the minimum value of an empty dataset.");
        }

        // Find the minimum value by iterating through the data
        return std::min_element(data_.begin(), data_.end())->first;
    }

    EInteger Histogram::getMaxValue() const {
        if (data_.empty()) {
            // Handle the case when the dataset is empty
            throw std::runtime_error("Error: Cannot find the maximum value of an empty dataset.");
        }

        // Find the maximum value by iterating through the data
        return std::max_element(data_.begin(), data_.end())->first;
    }

}  // namespace Hist
