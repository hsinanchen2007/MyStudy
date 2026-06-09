### 解题思路
首先找到num的最高为1的位，然后通过右移镜像复制的形式，生成一个x，该x中对应num最高位及以下为全为1，其余的位为0
例如 num为10110  x就为11111
### 代码

```cpp
class Solution 
{
public:
    int findComplement(int num) 
    {
        uint32_t x = num;

        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return (~num) & x;
    }
};
```