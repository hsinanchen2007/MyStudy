### 解题思路
1.用1位1做掩码，遍历整个数字，用掩码与其做与运算，非零则为1，并在计数器上做加一操作。

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) != 0) {
                bits++;
            }
            mask <<= 1;
        }
        return bits;
    }
};
```