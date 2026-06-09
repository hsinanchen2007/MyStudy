### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) 
    { 
         int  count=0;
         uint32_t res=0;
         while(n)
        {
            if(n&1==1)  {++count;}  
           n=n>>1;
        }
        return count;
    }
};
```