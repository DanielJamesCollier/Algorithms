// std
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <chrono>
#include <cstddef>

using namespace std::chrono_literals;

//----------------------
template<typename T, std::size_t size>
void
merge(std::array<T, size> &array, decltype(size) left, decltype(size) middle, decltype(size) right) {
    
    auto n1 = middle - left + 1;
    auto n2 = right - middle;
    
    std::vector<T> left_array(n1);
    std::vector<T> right_array(n2);
    
    for (decltype(n1) i = 0; i < n1; i++) {
        left_array[i] = array[left + i];
    }
    
    for (decltype(n2) j = 0; j < n2; j++) {
        right_array[j] = array[middle + 1 + j];
    }
    
    decltype(size) i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        ++k;
    }
    
    while (i < n1) {
        array[k] = left_array[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        array[k] = right_array[j];
        j++;
        k++;
    }
}

//----------------------
template<typename T, std::size_t size>
void
merge_sort(std::array<T, size> &array, decltype(size) left, decltype(size) right) {
    if (left < right) {
        decltype(size) middle {(left + right) / 2};
        
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

//----------------------
template<typename T, std::size_t size>
void
merge_sort(std::array<T, size> &array) {
    merge_sort(array, 0, array.size() - 1);
}

//----------------------
template<typename T, std::size_t size>
void
fill_array_with_rand(std::array<T, size> &array) {
    for (auto & i : array) {
        i = rand() % 100;
    }
}

//----------------------
template<typename T, std::size_t size>
bool
is_sorted(std::array<T, size> &array) {
    for (decltype(size) i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

//----------------------
template<typename T, std::size_t size>
void
print_array(std::array<T, size> &array) {
    for (decltype(size) i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
}

//----------------------
int
main() {
    constexpr std::size_t size = 3'000;
    std::array<int, size> array;
    fill_array_with_rand(array);
    
    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(array);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::cout << "sort time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    std::cout << "is sorted?: " << (is_sorted(array) ? "yes" : "no") << std::endl;
    
    std::string pause;
    std::cin >> pause;
    return 0;
}
