### 解题思路

![sas.png](https://pic.leetcode-cn.com/11cb608cb934c42f6a72281913d358ae6ff7eebba6df1f4937be1f9b8d7e94f5-sas.png)

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<33> bit(n);
        return bit.count() == 1;
    }
};
```