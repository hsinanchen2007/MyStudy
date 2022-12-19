### 解题思路

动态规划

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int dp=0;
        for(int i=2;i<=n;i++)dp=(dp+m)%i;
        return dp;
    }
};
```