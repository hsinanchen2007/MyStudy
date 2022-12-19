### 思路
阶乘末尾0的个数，即找乘数中10的个数，10可由2和5相乘得到，而2的数量又远远大于5的数量，所以可以统计5的数量，对于25， 125等含有多个5，5的个数都要统计。

### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};
```