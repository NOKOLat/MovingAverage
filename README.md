# Moving Average (移動平均)
## Summary
This library is inheritance class of `std::array` to use moving average.

このライブラリは移動平均を使うための`std::array`の継承クラスです．

## usage
### initializer
```
template<typename _Tp, std::size_t _Nm>
struct MovingAverage: public std::array<_Tp, _Nm>;
```
Initializers  is same as `std::array`.

### member function
#### getAverage
```
template<typename T=float> T getAverage();
```
This function is used to get average of buffer.
The return value type is a template. So, please specify it if necessary.

この関数は，配列の変数を取得するために使用する．
返り値の型はテンプレート化されており必要に応じてdouble型などを指定する．

#### push
```
void push(_Tp value)
```
This function overwrites an oldest value in array with an argument `value`.
この関数は，最も古い要素を上書きします．

## sample
```c++
#include "movingAverage"
#include <iostream>

int main(){
    MovingAverage<int, 5> mov = {0, 1, 2, 3, 4};

    std::cout << mov << std::endl; // 0, 1, 2, 3, 4
    std::cout << mov.getAverage() << std::endl; // 2

    mov.push(5);
    std::cout << mov << std::endl; // 5, 1, 2, 3, 4
    std::cout << mov.getAverage() << std::endl; // 3

    mov.push(6);
    std::cout << mov << std::endl; // 5, 6, 2, 3, 4
}
```