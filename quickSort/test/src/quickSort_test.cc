#include "quickSort.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <random>

namespace sort {
TEST(SortTest, appriopriateSorting) {
    const int n = 20;

    std::vector<int> vec(n);

    std::random_device rnd;
    std::mt19937 engine{rnd()};
    std::uniform_int_distribution<int> distr{1, 100};

    auto gen = [&distr, &engine]() {
        return distr(engine);
    };

    std::generate(vec.begin(), vec.end(), gen);
    std::vector<int> reference{vec};

    quickSort<int>(reference.begin(), reference.end());
    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) {
        ASSERT_EQ(vec[i], reference[i]);
    }
}
}  // namespace sort
