### 解题思路
不断的取n的最低位并右移，加到ret上并左移，从而实现颠倒

### 代码

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret=0;
        int i=0;
        int number;
        while(i<32)
        {
            ret=ret<<1;
            number=(n&1);
            ret=(ret|number);
            n=n>>1;
            ++i;
        }
        return ret;
    }
};
```