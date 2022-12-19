### 解题思路
一个正整数的补数 2^(二进制数的个数) - 1 - num

### 代码

```cpp
class Solution {
public:
    int findComplement(int num) {
        int sz = log(num)/log(2) +1;
        return pow(2, sz)-1-num;
    }
};
```