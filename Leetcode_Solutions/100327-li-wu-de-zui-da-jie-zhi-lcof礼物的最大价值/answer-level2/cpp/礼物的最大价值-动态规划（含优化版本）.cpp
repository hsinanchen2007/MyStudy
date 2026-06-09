### 解题思路
1. 可以很清楚的知道，到达一个格子的方法只能从左边或者从上面到达
2. 那么在当前格子时，只要选max(左边格子的累和，上边格子的累和) + 当前格子的值即可
3. 定义状态：`dp[i][j]`为到达格子`grid[i][j]`时达到最大值
4. 转态转移方程：`dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + grid[i][j]`
5. 有个问题是：第一列的格子和第一行的格子作为边界，不能从左边或者上边的格子走到该格子，因此dp数组增加一行和一列,它们的值都为0，方便处理

###代码

```
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0) return 0;
        int cols = grid[0].size();
        if(cols == 0) return 0;
        int dp[rows+1][cols+1];
        //初始化
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= rows; i++)
            for(int j = 1; j <= cols; j++)
                dp[i][j] = max(dp[i][j-1] + grid[i-1][j-1], dp[i-1][j] + grid[i-1][j-1]);
        return dp[rows][cols];
    }
};
```

### 优化版本
上面版本的代码可以看出来，当前`dp[i][j]`的值除了依赖`grid[i-1][j-1]`的值以外，只依赖于`dp[i][j-1]`和`dp[i-1][j]`。也就是说，当我们处理`dp[i][j]`时，除了`dp[i][j-1]`和`dp[i-1][j]`这两个dp数组元素的值以外，dp数组的其他元素是用不上的。值得注意的是，当我们要处理时`dp[i][j]`，`dp[i][j-1]`和`dp[i-1][j]`已经先处理过了!!!
那么我们可以定义一个一维dp数组，表示为处理完第i行grid之后得到的值。那么我们处理第i+1行grid时，就可以用第i行处理的结果得到！即代码中的`dp[j] = max(dp[j-1]+grid[i][j-1], dp[j]+grid[i][j-1]);` 



### 优化版本代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0) return 0;
        int cols = grid[0].size();
        if(cols == 0) return 0;
        int dp[cols+1];
        dp[0] = 0;
        //初始化dp第一行的值
        for(int i = 1; i <=cols; i++){
            dp[i] = grid[0][i-1] + dp[i-1];
        }
        for(int i = 1; i < rows; i++)
            for(int j = 1; j <= cols; j++)
                dp[j] = max(dp[j-1]+grid[i][j-1], dp[j]+grid[i][j-1]);
        return dp[cols];
    }
};
```