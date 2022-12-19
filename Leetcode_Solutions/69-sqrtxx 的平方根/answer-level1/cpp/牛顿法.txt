### 解题思路
求n的平方根，等价于求方程x^2 - n = 0的根，记f(x) = x^2 - n
由牛顿法得x的迭代方程 x' = x - f(x)/f'(x),
由于f'(x) = 2x，故x' = x - (x^2 - n) / (2x) = (x + n / x) / 2
不断迭代更新直到误差小于给定的err即可
### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        double n = x;
        double res = x / 2;//随意给出初始值
        double err = 0.001;//随意指定误差
        
        while(labs(res * res - n) > err){
            res = (res + n / res) / 2;
        }
        
        return res;
    }
};
```