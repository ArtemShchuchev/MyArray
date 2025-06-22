#include <iostream>


template<class T, size_t _size>
class Array
{
private:
    T arr[_size];

public:
    Array() = default;
    Array(std::initializer_list<T> init) {
        for (size_t i(0); i < _size; ++i) {
            arr[i] = *(init.begin() + i);
        }
    }

    T& operator[] (const int idx) {
        return arr[idx];
    }
    const T& operator[] (const int idx) const {
        return arr[idx];
    }
    size_t size() const { return _size; }
    const T* begin() const { return &arr[0]; }
    const T* end() const { return (&arr[0] + _size); }
    
    friend std::ostream& operator<< (std::ostream& os, const Array& arr) {
        for (const auto& data : arr) {
            os << data << " ";
        }
        return os << std::endl;
    }
};

int main()
{
    Array<int, 6> arr{ 3,4,5,6,7,8 };
    std::cout << arr;
    std::cout << "arrSize: " << arr.size() << "\n";

    arr[3] = 25;
    std::cout << arr;
}
