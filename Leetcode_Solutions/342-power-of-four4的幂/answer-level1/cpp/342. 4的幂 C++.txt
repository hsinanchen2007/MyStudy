### 解题思路
1.4的幂的二进制位1都在偶数位上。
2.判断是否num大于0，再判断是否是2的幂，因为是4的幂就一定是2的幂，在与0xAAAAAAAA想与，其二进制上所有偶数位均为1。
3.以上条件均成立表示该数是4的幂。

### 代码

```cpp
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0xAAAAAAAA) == 0);
    }
};
```