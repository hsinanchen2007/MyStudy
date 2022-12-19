```cpp
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        // 计算掩码
        uint32_t mask1 = UINT32_MAX << i;
        uint32_t mask2 = UINT32_MAX >> (32 - j - 1);
        uint32_t mask = mask1 & mask2;

        // 保留 N 中 [i, j] 以外的位，保留 M [i, j] 之间的位
        return (N & (~mask)) + ((M << i) & mask);
    }
};
```
