## 思路一：循环
循环二进制位数。

### 代码
时间复杂度：O(1)
空间复杂度：O(1)
```c++
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

## 思路二：位操作技巧
**特性：n & (n-1)将n的二进制表示中最右侧1置为0**

### 代码
时间复杂度：O(1)
空间复杂度：O(1)
```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        while (n) {
            ++c;
            n = n & (n-1);//将n二进制表示中最右侧1置为0
        }
        return c;
    }
};
```