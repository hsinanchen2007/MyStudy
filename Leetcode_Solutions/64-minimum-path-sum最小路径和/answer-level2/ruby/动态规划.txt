### 解题思路
最短路径问题，首先想到的就是动态规划。
动态规划找递推公式。
最右下角的那个位置可以从两个位置到达，一个是正上方，一个是左前边，即想到公式：
dp[i,j] = [dp[i-1][j] + dp[j][j-1]].min + dp[i,j]
意思是：左前方最短的路径或者正上方的最短路径的最小值 + 当前位置。
需要考虑的特殊情况是，第一行与最右边一行特殊处理

### 代码

```ruby
# @param {Integer[][]} grid
# @return {Integer}
def min_path_sum(grid)
    for i in (0..grid.size-1) do 
        for j in (0..grid[i].size-1) do 
            if i == 0 && j == 0
                next
            end
            if i == 0 
                grid[i][j] = grid[i][j-1] + grid[i][j]
            elsif j == 0
                grid[i][j] = grid[i-1][j] + grid[i][j]
            else
                grid[i][j] = [grid[i][j-1], grid[i-1][j]].min + grid[i][j]
            end
        end
    end
    return grid[-1][-1]
end
```