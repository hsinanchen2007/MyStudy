### 解题思路
产生0需要5与2相乘
统计1~n中能被5整除的个数n5，能被2整除的个数n2，本轮取min(n5, n2)
然后继续寻找1~n5中能被5整除的个数，1~n2中能被2整除的个数，重复之前的操作
直到二者整除个数中有一个为0，即退出
### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) {
            return 0;
        }
        int res = 0;
        int fives = n / 5;
        int twos = n / 2;
        while (fives && twos) {
            res += min(fives, twos);
            fives /= 5;
            twos /= 2;
        }
        return res;
    }
};
```