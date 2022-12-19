### 解题思路
此处撰写解题思路
这个题是位运算的基础.
也不难.
### 代码

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t cnt=0;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
            {
                cnt+=(1<<(31-i));
            }
        }
        return cnt;
    }
};
```