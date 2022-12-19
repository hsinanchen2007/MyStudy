dp[i][j] 表示以坐标(i, j)为右下角的矩阵有多少个


方法一: 直接DP
```python

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        
        row, col = len(matrix), len(matrix[0])
        dp = [[0] * col for _ in range(row)]
        
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == 0:
                    dp[i][j] = 0
                    continue 
                if i == 0 or j == 0:
                    dp[i][j] = matrix[i][j]
                else:
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
                    
        print(dp)
        return sum(map(sum, dp))
    
```
时间复杂度O(mn)
空间复杂度O(mn)


方法二： 换种方法

如果 matrix[i][j] == 0： **dp[i][j] = 0**
如果 matrix[i][j] == 1： **dp[i][j] = min(dp[i - 1, j - 1], 左边连续1的个数, 上边连续1的个数) + 1**
    

- 对于上边连续1的个数我们可以用top数组进行保存:

    如果 matrix[i][j] == 1: **top[j] += 1**  # 更新top
    如果 matrix[i][j] == 0: **top[j] = 0**  #  top置0

  对于左边连续1的个数我们可以在遍历j的时候进行计算:
    如果 matrix[i][j] == 1: left_max += 1 # 更新left_max
    如果 matrix[i][j] == 0: left_max = 0 # left_max置0


```python
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        row, col = len(matrix), len(matrix[0])
        dp = [[0] * col for _ in range(row)]
        top = [0] * col # 保存该点上边连续1的个数
        for i in range(row):
            left_max = 0
            for j in range(col):
                if matrix[i][j] == 0:
                    left_max = dp[i][j] = top[j] = 0
                    continue
                if i == 0 or j == 0:
                    dp[i][j] = matrix[i][j]
                else:
                    dp[i][j] = min(dp[i - 1][j - 1], left_max, top[j]) + 1
                top[j] += 1 # 如果 matrix[i][j] !=0 更新上边连续1的个数
                left_max += 1 # 如果matrix[i][j] != 0 更新左边连续1的个数
        
        return sum(map(sum, dp)) # 汇总
```


时间复杂度 **O(mn)**
空间复杂度 **O(mn)**