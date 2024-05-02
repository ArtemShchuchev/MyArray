#include <iostream>

template<class T, int _size>
class Array {
private:
    T arr[_size];

public:
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

static void print(myArr arr) {
    for (int i(0); i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Hello World!\n";

    myArr arr{ {1,2,3,4,5,6} };
    print(arr);
    std::cout << "arrSize: " << arr.size() << "\n";
    arr[0] = 3;
    arr[2] = 25;
    print(arr);
}
