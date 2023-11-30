#pragma once

#include <utility>
#include <vector>

namespace sort {

namespace {

template <typename T>
typename std::vector<T>::iterator partition(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
    auto begRef{begin};
    auto ptr{begin++};

    for (begin; begin != end; ++begin) {
        if (*begin < *begRef) {
            ptr++;
            auto temp{*begin};
            *begin = *ptr;
            *ptr = temp;
        }
    }

    auto temp{*begRef};
    *begRef = *ptr;
    *ptr = temp;

    return ptr;
}

template <typename T>
typename std::vector<T>::iterator partition(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, bool (*fp)(const T& lhs, const T& rhs)) {
    auto begRef{begin};
    auto ptr{begin++};

    for (begin; begin != end; ++begin) {
        if (fp(*begin, *begRef)) {
            ptr++;
            auto temp{*begin};
            *begin = *ptr;
            *ptr = temp;
        }
    }

    auto temp{*begRef};
    *begRef = *ptr;
    *ptr = temp;

    return ptr;
}

}  // namespace

template <typename T>
void quickSort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
    if (std::distance(begin, end) > 0) {
        auto pivotPoint{std::move(partition<T>(begin, end))};
        quickSort<T>(begin, pivotPoint);
        quickSort<T>(pivotPoint + 1, end);
    }
}

template <typename T>
void quickSort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, bool (*fp)(const T& lhs, const T& rhs)) {
    if (std::distance(begin, end) > 0) {
        auto pivotPoint{std::move(partition<T>(begin, end, fp))};
        quickSort<T>(begin, pivotPoint, fp);
        quickSort<T>(pivotPoint + 1, end, fp);
    }
}

}  // namespace sort
