### 解题思路

### 代码

```cpp
class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int num=0;

        for(int i=0;i<8*sizeof(n);i++)
            if((n>>i)&1) num++;
        
        return num;
    }
};
```