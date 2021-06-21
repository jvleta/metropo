#include <cstdlib>
#include <random>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main(int argc, char *argv[]) {

  int npoints = std::atoi(argv[1]);

  std::random_device device{};
  std::mt19937 rng{device()};
  std::normal_distribution<> normal_dist{0, 1};
  std::vector<double> v;

  for (int i = 0; i < npoints; ++i) {
    v.push_back(normal_dist(rng));
  }

  plt::hist(v);
  plt::xlabel("xdata");
  plt::grid(true);
  plt::show();
}
