### 解题思路
![image.png](https://pic.leetcode-cn.com/b1be4346077ff8bdba586b7d7235ab68121bdcb3149d4ac749ba3134ed496f9f-image.png)

- 这是一个典型的二维的DP问题,根据题目的要求,现在我们做如下设定:
- 设定`dp[raw][col]`为到达第`raw`行,第`col`列时路径上面的最小值,下面我们开始写转移方程
- 由于题目的限制我们只能向下或者向右移动,那么我们的`dp[raw][col] = min(dp[raw-1][col],dp[raw][col-1]) + grid[raw][col]`,也就是当前的最小值是由这个位置的上面和左面的最小值决定的,取上面和左面的最小的那一个在加上本身的值就是当前的路径的最小值了
- 在这个过程中我们需要统计整个二维dp数组的值,然后返回最后一个即可
- 在实现的过程中需要注意下,`raw=0`和`col=0`的情况,具体的看代码注释

### 代码

```python
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        raws = len(grid)
        cols = len(grid[0])
        dp = [[0]*cols for _ in range(raws)]#构建二维dp数组
        dp[0][0] = grid[0][0]#初始化第一个值
        for raw in range(raws):
            for col in range(cols):
                if raw == 0 and col == 0:#当遇到第一个值时跳过,因为之前已经赋值了
                    continue
                if raw == 0:#当访问第一行的元素时,这时只需将第1行前面的元素相加即可
                    dp[raw][col] = dp[raw][col-1] + grid[raw][col]
                elif col == 0:#当访问第一列的元素时,这时只需将第1列前面的元素相加即可
                    dp[raw][col] = dp[raw-1][col] + grid[raw][col]
                else:#这是就根据转移方程计算
                    dp[raw][col] = min(dp[raw-1][col],dp[raw][col-1]) + grid[raw][col]
                    
        return dp[raws-1][cols-1] #返回最后一个值















```