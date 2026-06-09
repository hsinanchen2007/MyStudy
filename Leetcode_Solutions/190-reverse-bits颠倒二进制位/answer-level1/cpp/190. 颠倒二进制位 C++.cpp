### 解题思路
1.取原值的某位添加在返回值的第一位。
2.原值向后移动一位，返回值向前移动一位。
3.循环32边后返回值。

### 代码

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0;i < 32;i++){
            ans <<= 1;
            ans += (n & 1);
            n >>= 1;
        }
        return ans;
    }
};
```