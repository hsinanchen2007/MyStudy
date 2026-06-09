### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count=0;
        
        while(n)
        {
            count++;
            n=n&(n-1);

        }
        return count;
    }
};
```