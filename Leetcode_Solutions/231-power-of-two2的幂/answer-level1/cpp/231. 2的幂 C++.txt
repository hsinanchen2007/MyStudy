### 解题思路
1.2的幂级数的二进制表达式中只含有1个1，若它减1，它的二进制就变成少一位的全1，与它原数相与，若为0则表示是2的幂，若不是则也不是2的幂。

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        long x = n;
        return (x & (x - 1)) == 0;
    }
};
```