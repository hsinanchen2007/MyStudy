### 解题思路
将matrix作转置并用matrix_T表示，所以求matrix的列最大就变为了求其转置matrix_T的行最大。因此我们分别记录matrix的所有行最小和matrix_T的所有列最大，然后取交集便是我们满足题意的元素。之所以作以上转变是因为求行最值比列最值简便。

### 代码

```python3
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        row,col = len(matrix),len(matrix[0])
        matrix_T =[[None]*row for _ in range(col)]
        for r in range(row):
            for c in range(col):
                matrix_T[c][r] = matrix[r][c]
        row_min = set()
        for r in range(row):
            row_min.add(min(matrix[r]))
        col_max = set()
        for c in range(col):
            col_max.add(max(matrix_T[c]))
        ans = []
        for num in row_min:
            if num in col_max:
                ans.append(num)
        return ans
```