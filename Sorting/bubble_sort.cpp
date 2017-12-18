// std
#include <string>
#include <iostream>
#include <array>
#include <chrono>
#include <cstddef>

using namespace std::chrono_literals;

//----------------------
template<std::size_t size>
void
bubble_sort(std::array<int, size> &array) {
    for (decltype(size) i = 0; i < size - 1; ++i) {
        for (decltype(size) j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                auto temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//----------------------
template<std::size_t size>
void
fill_array_with_rand(std::array<int, size> &array) {
    for (auto &i : array) {
        i = rand() % 100;
    }
}

//----------------------
template<std::size_t size>
void
fill_array_with_rand(std::array<int, size> &array) {
    for (auto & i : array) {
        i = rand() % 100;
    }
}

//----------------------
template<std::size_t size>
bool
is_sorted(std::array<int, size> &array) {
    for (decltype(size) i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

//----------------------
int
main() {
    constexpr std::size_t size = 3'000;
    std::array<int, size> array;
    fill_array_with_rand(array);
    
    auto start = std::chrono::high_resolution_clock::now();
    bubble_sort(array);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::cout << "sort time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    std::cout << "is sorted?: " << (is_sorted(array) ? "yes" : "no") << std::endl;
    
    std::string pause;
    std::cin >> pause;
    return 0;
}
