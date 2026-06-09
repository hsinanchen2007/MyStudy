# 毎日一题 -  64.最小路径和

## 信息卡片

* 时间：2019-08-09
* 题目链接：https://leetcode-cn.com/problems/minimum-path-sum/
- tag：`动态规划` `Array`
## 题目描述
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
**说明**：每次只能向下或者向右移动一步。
**示例:**
```
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
```
## 参考答案

### 思路

我们新建一个额外的dp数组，与原矩阵大小相同。在这个矩阵中,dp(i,j)表示从原点到坐标(i,j)的最小路径和。我们初始化dp值为对应的原矩阵值，然后去填整个矩阵，对于每个元素考虑从上方移动过来还是从左方移动过来，因此获得最小路径和我们有如下递推公式：`dp(i,j)=grid(i,j)+min(dp(i-1,j),dp(i,j-1))`


我们可以使用原地算法，这样就不需要开辟dp数组，空间复杂度可以降低到$O(1)$。


### 代码

C++

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        if(m==0)
            return 0;
        //初始化第一行
        for(int i=1;i<m;i++)
        {
            grid[0][i] += grid[0][i-1];
        }
        //初始化第一列
        for(int i=1;i<n;i++)
        {
            grid[i][0] += grid[i-1][0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                //计算出到当前位置的最小值
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};
```

JavaScript：

```js
var minPathSum = function(grid) {
// 时间复杂度和空间复杂度都是 O (m * n);
  if (grid.length === 0) return 0;
  const dp = [];
  const rows = grid.length;
  const cols = grid[0].length;
  // 实际上你也可以无差别全部填充为MAX_VALUE，对结果没影响,代码还会更少
  // 只是有点不专业而已
  for (let i = 0; i < rows + 1; i++) {
    dp[i] = [];
    // 初始化第一列
    dp[i][0] = Number.MAX_VALUE;
    for (let j = 0; j < cols + 1; j++) {
      // 初始化第一行
      if (i === 0) {
        dp[i][j] = Number.MAX_VALUE;
      }
    }
  }

  // tricky
  dp[0][1] = 0;

  for (let i = 1; i < rows + 1; i++) {
    for (let j = 1; j < cols + 1; j++) {
      // state transition
      dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
    }
  }

  return dp[rows][cols];
};

```

Python3:

```python
class Solution:
    def minPathSum(self, grid: [[int]]) -> int:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == j == 0: continue
                elif i == 0:  grid[i][j] = grid[i][j - 1] + grid[i][j]
                elif j == 0:  grid[i][j] = grid[i - 1][j] + grid[i][j]
                else: grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j]
        return grid[-1][-1]
```

**复杂度分析**
- 时间复杂度：$O(M * N)$
- 空间复杂度：$O(1)$


欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)


