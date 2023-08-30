#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <HistogramBase.h>
#include <unordered_map>

namespace Hist {

    class Histogram : public HistogramBase {
    public:
        // Constructor takes a logger
        Histogram(std::unique_ptr<Logger> logger);

        // Destructor
        ~Histogram() override;

        // Add an element to the histogram
        void add(EInteger value) override;

        // Return the mode of the dataset
        virtual EInteger getMode() const override;

        // Return the smallest value in the dataset
        virtual EInteger getMinValue() const override;

        // Return the largest value in the dataset
        virtual EInteger getMaxValue() const override;

    private:
        std::unordered_map<EInteger, int> data_;
    };

} // namespace Hist

#endif // HISTOGRAM_H
