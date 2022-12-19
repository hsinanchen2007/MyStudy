### 解题思路
优化版本的动态规划。
分析过程：
//原始版本
1、动态规划的状态dp[i][j]表示到位置（i,j）可获得的最大礼物价值；
2、动态规划的递推公式为dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
3、动态规划的边界条件为：第一行（第一列）只能从左至右（从上至下）累加；
代码如下：

### 代码
```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for(size_t i=1; i<grid.size(); ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(size_t j=1; j<grid[0].size(); ++j) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(size_t i=1; i<grid.size(); ++i) {
            for(size_t j=1; j<grid[0].size(); ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
    
};
```

//优化版本
   上述版本需要与grid同样大小的二维数组空间来存储中间dp值。有递归过程中，仅使用上侧和左侧的值，因此只需保留上一行dp值、并从左至右从上至下检索即可，因此可进行空间优化，只用使用一维数组即可。具体描述如下：
4、状态dp[j]:某行第j列可获得的最大礼物值；
5、递推公式：dp[j] = max(dp[j-1], dp[j]) + grid[i][j]
6、边界条件：第一行只能从左至右累加。
代码如下

### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        vector<int> dp(grid[0].begin(), grid[0].end());
        for(size_t j=1; j<dp.size(); ++j) {
            dp[j] += dp[j-1];
        }

        for(size_t i=1; i<grid.size(); ++i) {
            dp[0] += grid[i][0]; //注意更新最左侧dp值
            for(size_t j=1; j<grid[0].size(); ++j) {
                dp[j] = max(dp[j-1], dp[j]) + grid[i][j];
            }
        }
        return dp.back();
    }
    
};
```
![image.png](https://pic.leetcode-cn.com/2595817d0271ccbe4f3a80397200b4be661214a9a626aae80d13d643d7e5d850-image.png)

两个版本运行情况对比
![image.png](https://pic.leetcode-cn.com/635ff2cd17c7eb610669a1588c92cf1af3bdd18c99977a01b9a7d47fa7fde59d-image.png)

