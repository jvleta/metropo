#include <cstdlib>
#include <random>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main(int argc, char *argv[]) {

  int npoints = std::atoi(argv[1]);

  std::random_device device{};
  std::mt19937 rng{device()};
  std::normal_distribution<double> normal_dist1{0, 1};
  std::normal_distribution<double> normal_dist2{1, 2};
  std::vector<double> x;
  std::vector<double> y;
  std::vector<double> z;

  for (int i = 0; i < npoints; ++i) {
    auto xsample = normal_dist1(rng);
    auto ysample = normal_dist2(rng);
    auto zsample = xsample + 5.0 * ysample;
    x.push_back(xsample);
    y.push_back(ysample);
    z.push_back(zsample);
  }

  plt::figure();

  plt::subplot(3, 1, 1);
  plt::hist(x);

  plt::subplot(3, 1, 2);
  plt::hist(y);

  plt::subplot(3, 1, 3);
  plt::hist(z);

  plt::show();
}
