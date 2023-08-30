#include "HistogramBase.h"

namespace Hist {

    // Constructor
    HistogramBase::HistogramBase(std::unique_ptr<Logger> logger)
        : m_log(std::move(logger)) {
        // Initialize any other members as needed
    }

    // Copy constructor
    HistogramBase::HistogramBase(const HistogramBase& other)
        : m_log(std::make_unique<Logger>(*other.m_log)) {
        // Copy any other members as needed
    }

    // Move constructor
    HistogramBase::HistogramBase(HistogramBase&& other) noexcept
        : m_log(std::move(other.m_log)) {
        // Move any other members as needed
    }

    // Destructor
    HistogramBase::~HistogramBase() {
        // Destructor implementation if needed
    }

} // namespace Hist
