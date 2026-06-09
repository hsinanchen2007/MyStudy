## 思路
循环判断最后一位是否为1。

### 代码
时间复杂度：O(1)
空间复杂度：O(1)
```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 0x1 == 1) ++res;
            n >>= 1;
        }
        return res;
    }
};
```