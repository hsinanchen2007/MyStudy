### 解题思路
利用STL自带的bitset统计比特位

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bs(n);
        return bs.count();
    }
};
```