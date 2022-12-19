### 解题思路
i代表行数和每行硬币数，n逐行减少i个，当i行大于n的时候代表**剩余硬币数量无法在该行构成一行**，此时i-1就是总行数。

### 代码

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        
        int i;
        for(i=1;i<=n;i++)
        {
            n-=i;
        }
        
        return i-1;
        

    }
};
```