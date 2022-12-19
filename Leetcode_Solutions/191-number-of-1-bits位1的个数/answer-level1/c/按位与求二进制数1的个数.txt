### 解题思路
按位与操作:1<<i，而不是i<<1

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        for(int i=0;i<32;i++)
        {
            if(n & (1<<i))
                num++;
        }
        return num;
    }
};
```