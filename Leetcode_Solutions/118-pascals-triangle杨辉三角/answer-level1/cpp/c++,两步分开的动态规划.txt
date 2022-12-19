### 解题思路
此处撰写解题思路
![捕获.JPG](https://pic.leetcode-cn.com/42d4aa715185986992f1302038fc7f24cdbf18123d14c6ec01c034af5228bedd-%E6%8D%95%E8%8E%B7.JPG)
两步：
1、先一个循环构造杨辉三角的边角值
2、再利用动态方程dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; ++i) {
            ans[i] = vector<int>(i+1,0);
            ans[i][0] = 1;
            ans[i][i] = 1;
        }
        if (numRows <= 2) return ans;
        for (int i = 2; i < numRows; ++i)
            for (int j = 1; j < ans[i].size()-1; ++j) ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        return ans;
    }
};
```