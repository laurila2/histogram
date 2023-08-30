// HistogramBase.cpp
#include "HistogramBase.h"

namespace Hist {
    HistogramBase::HistogramBase(std::unique_ptr<Logger> logger)
        : m_log(std::move(logger)) {
        // Constructor implementation, if needed
    }

    HistogramBase::~HistogramBase() {
        // Destructor implementation, if needed
    }
}
