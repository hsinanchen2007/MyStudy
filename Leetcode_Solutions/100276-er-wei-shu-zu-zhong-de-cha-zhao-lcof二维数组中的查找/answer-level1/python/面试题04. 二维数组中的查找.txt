### 解题思路
很有意思的题目，通过判断第一行最后一个和第一列最后一个缩小范围。即当target 小于第一行最后一个时，他肯定小于该列的所有值

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0])==0:
            return False
        if target < matrix[0][0] or target > matrix[-1][-1]:
            return False
        H = len(matrix)
        W = len(matrix[0])
        w = W - 1
        while w > 0 :
            if matrix[0][w] == target:
                return True          
            if matrix[0][w] > target:
                w -= 1
            else:
                break
        h = H - 1
        while h > 0:
            if matrix[h][0] == target:
                return True
            if matrix[h][0] > target:
                h -=1
            else:
                break

        for i in range(h+1):
            for j in range(w+1):
                if matrix[i][j] == target:
                    return True
        return False
         
```