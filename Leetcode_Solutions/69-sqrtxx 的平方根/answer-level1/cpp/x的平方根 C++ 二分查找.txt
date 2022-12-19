### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // 二分法
    int mySqrt(int x) {
        if (x == 1) return 1;
        int min = 0;
        int max = x;
        while (max-min > 1) {
            // 二分查找，m去二分值
            int m = (max+min)/2;
            // 用x/m<m而不是m*m>x是为了防止溢出
            if (x/m<m)
                max = m;
            else
                min = m;
        }
        return min;
    }
    
    // // 牛顿法
    // // f(x) = x^2 - a     求解 a 的平方根, 即求解 f(x) = 0 的解
    // // f(x) ~= f(x0) + (x - x0) * f'(x0);
    // // 令 f(x) = 0   =>   x = (x0 + a/x0) /2	=> 得到该迭代公式.
    // int mySqrt(int a) {
    //     long x0 = a;
    //     while (x0*x0 > a) {
    //     	x0 = (x0 + a / x0) / 2;
    //     }
    //     return (int)x0;
    // }
};



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mySqrt(int x) {
    if (x == 1) return 1;
    int min = 0;
    int max = x;
    while (max-min > 1) {
        int m = (max+min)/2;
        if (x/m<m) max = m;
        else min = m;
    }
    return min;
}

int main() {
    cout << mySqrt(4) << endl;
}

```