### 解题思路
从题目中可以看出每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
从右上角开始找一个数如果这个目标比此时的值小就往左走，反之大就往下走。
### 代码

```python3
class Solution:
    def find(self, matrix, target):
        rows = len(matrix) ##矩阵中有多少个一维数组
        if rows == 0:
            return False
        cols = len(matrix[0]) ##一维数组里面有多少个值
        if cols == 0:
            return False
        x = 0
        y = cols - 1 
        while x < rows and y >= 0:  ## 此处即是判断条件同时防止索引越界。
            if target == matrix[x][y]:  ##xy定位到右上角
                return True
            elif target < matrix[x][y]:
                y -= 1
            else:
                x += 1
        return False
```