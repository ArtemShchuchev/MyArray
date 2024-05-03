#include <iostream>

/*
template<class T, int _size>
class Array {
private:
    T arr[_size];

public:
    Array() = default;
    Array(std::initializer_list<T> init) {
        auto ptr = init.begin();
        for (int i(0); i < _size; ++i) {
            arr[i] = *ptr;
            ++ptr;
        }
    }

    T& operator[] (const int idx) {
        return arr[idx];
    }
    const T& operator[] (const int idx) const {
        return arr[idx];
    }
    int size() const { return _size; }
};

const int SIZE_ARR(6);
using myArr = Array<int, SIZE_ARR>;
*/

template<class T>
class Array
{
private:
    T* arrPtr;
    int _size;

public:
    Array() = default;
    Array(T* ptr, int size) : arrPtr(ptr), _size(size) {}

    T& operator[] (const int idx) {
        return arrPtr[idx];
    }
    const T& operator[] (const int idx) const {
        return arrPtr[idx];
    }
    int size() const { return _size; }
};

template<class T>
static void print(const Array<T> arr) {
    for (int i(0); i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Hello World!\n";

    int a[]{ 3,4,5,6,7,8 };
    Array<int> arr{ a, sizeof(a)/sizeof(int)};
    print(arr);
    std::cout << "arrSize: " << arr.size() << "\n";

    arr[3] = 25;
    print(arr);
}
