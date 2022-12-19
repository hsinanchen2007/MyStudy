### 解题思路
算法问题

### 代码

```cpp
class Solution {
public:int arrangeCoins(int n)
{
    int i = 0;
    while (1)
    {
        n -= i;
        if (n < i + 1)
            break;
        i++;
    }
    return i;
}
};
```