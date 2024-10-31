#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <functional>
#include <ranges>
#include <array>

namespace ranges = std::ranges;

int find_adjacent_common_height_in_adjacent_bars(std::vector<int> heights, int height_max){
    int frequency_height {}, start_frequency {}, end_frequency {};
    if (auto it = ranges::find(heights, height_max); it != heights.end()){
        start_frequency = ranges::distance(heights.begin(), it);

        if (auto it = ranges::adjacent_find(heights, ranges::greater()); it != heights.end())
            end_frequency = ranges::distance(heights.begin(), it);

        frequency_height = end_frequency - start_frequency + 1;
    }

    return frequency_height;
}
