### 解题思路
如果是2的幂，那么其二进制表示中有且仅有一个1.

### 代码

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int t = n;
        int ones = 0;
        while(t > 0){
            ones += (t & 1);
            t >>= 1;
        }
        return ones == 1;
    }
};
```