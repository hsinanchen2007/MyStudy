### 解题思路

### 代码

```cpp
class Solution 
{
public:
    uint32_t reverseBits(uint32_t n1) 
    {
        uint32_t n2=0;

        for(int i=0;i<32;i++)
            if((n1>>i)&1) n2|=(1<<(31-i));
        
        return n2;
    }
};
```
![image.png](https://pic.leetcode-cn.com/05acef88877e75151a054af11b499efd0f5c01b52f7fdd7a0867694e3509088a-image.png)
