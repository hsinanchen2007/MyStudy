### 解题思路

位运算，
### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int count = 0;
        while(n > 0)
        {
            count++;
             n = (n-1)&n;
        }
            return count;
    }

};
```