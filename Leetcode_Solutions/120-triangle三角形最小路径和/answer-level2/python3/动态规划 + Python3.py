### 解题思路
此处撰写解题思路
DP ： 借助triangle自身，存储到目前为止的最小值
转移方程：
    当值为首位， 只需要将自身与上一行同位置的值相加
       triangle[i][j] = triangle[i - 1][j] + triangle[i][j] 
    当值为末位， 只需要将自身与上一行末位相加
        triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j]
    当值为中间时， 需要比较与上一行两个相邻值的和取最小值
        triangle[i][j] = min(triangle[i - 1][j], triangle[i - 1][j - 1]) + triangle[i][j]
最优值：最后一行的最小值，即为自顶向下的最小路径。
### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle: return 0
        for i in range(1, len(triangle)):
            for j in range(len(triangle[i])):
                if j == 0:
                    triangle[i][j] = triangle[i - 1][j] + triangle[i][j]
                elif j == len(triangle[i]) - 1:
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j]
                else:
                    triangle[i][j] = min(triangle[i - 1][j], triangle[i - 1][j - 1]) + triangle[i][j]
        return min(triangle[-1])
```