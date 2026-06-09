![T1~@IDASLSS0TAE77B3YWS4.png](https://pic.leetcode-cn.com/d81e699d3e58abb6dfc7d6dabaab8aa477ac5e6b8a5373fbdfd30fe372e7bb27-T1~@IDASLSS0TAE77B3YWS4.png)

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int i = 0, j = 0, count = 1;
        ans[0][0] = 1;
        while(count < n * n) {
            while(j + 1 < n && !ans[i][j + 1]) ans[i][++j] = ++count;
            while(i + 1 < n && !ans[i + 1][j]) ans[++i][j] = ++count;
            while(j - 1 >= 0 && !ans[i][j - 1]) ans[i][--j] = ++count;
            while(i - 1 >= 0 && !ans[i - 1][j]) ans[--i][j] = ++count;
        }
        return ans;
    }
};
```
