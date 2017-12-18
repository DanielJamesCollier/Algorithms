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
insertion_sort(std::array<int, size> &array) {
    for (decltype(size) i = 1; i < size; i++) {
        int j = i - 1;
        int current = array[i];
        
        while (i > 0 && current < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}

//----------------------
template<std::size_t size>
void
print_array(std::array<int, size> &array) {
    for (decltype(size) i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
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
int
main() {
    constexpr std::size_t size = 3'000;
    std::array<int, size> array;
    fill_array_with_rand(array);
    
    auto start = std::chrono::high_resolution_clock::now();
    insertion_sort(array);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::cout << "sort time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    
    std::string pause;
    std::cin >> pause;
    return 0;
}
