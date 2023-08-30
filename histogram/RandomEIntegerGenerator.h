#ifndef RANDOMEINTEGERGENERATOR_H
#define RANDOMEINTEGERGENERATOR_H

#include "HistogramBase.h"
#include <random>

namespace Hist {

  class RandomEintegerGenerator : public RandomEintegerGeneratorBase {
  public:
    // Constructor
    RandomEintegerGenerator();

    // Destructor
    ~RandomEintegerGenerator();

    // Generate a random EInteger value
    EInteger operator()() override;

  private:
    std::mt19937_64 generator_;
  };

} // namespace Hist


#endif // RANDOMEINTEGERGENERATOR_H
