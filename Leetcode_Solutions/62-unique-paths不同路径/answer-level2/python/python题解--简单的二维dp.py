### 解题思路
![image.png](https://pic.leetcode-cn.com/6f8d5ad50a69687ed21fd607b4db176bc0650b59c1d67fdca83915fc3a6cd267-image.png)

- 此题和最小路径和的解法一模一样,设`dp[i][j]`表示到达节点`(i,j)`时的路径总和
- 根据题目要求只能向下或者向右移动,所以到达节点的路径应该是这两个方向的总和,可以写出状态转移方程为:
- `dp[i][j] = dp[i-1][j] + dp[i][j-1]`
- 空间复杂度`O(m*n)`

### 代码

```python
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[1]*n for _ in range(m)]

        for raw in range(m):
            for col in range(n):
                if raw == 0 or col == 0:
                    continue
                dp[raw][col] = dp[raw-1][col] + dp[raw][col-1]
        return dp[-1][-1]
```
### 优化版本
- 从上面转移方程可以看出来,第`(i,j)`的路径和是由上面的和左面的相加得到
- 我们设置一个一维的数组来保存每一行的节点的路径和,由于我们采取的是先遍历行在遍历列
- 假设现在的`cur`数组中保存的是第`i`行各节点的路径的和,当我们求第`i+1`行时,`cur[col] = cur[col-1] + cur[col]`,这里的没有更新的那个`cur[col]`就是`dp[i-1][j]`,`cur[clo-1]`就是`dp[i][j-1]`
- 空间复杂度变成了`O(n)`
### 代码
```
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        cur = [1]*n
        for raw in range(1,m):
            for col in range(1,n):
                cur[col] += cur[col-1]

        return cur[-1]
```
