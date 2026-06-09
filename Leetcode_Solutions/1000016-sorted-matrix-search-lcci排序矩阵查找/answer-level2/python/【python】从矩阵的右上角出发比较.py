### 解题思路
从右上角的元素出发：
（1）如果当前元素>目标值，说明这一列都大于目标值，向左移动一列
（2）如果当前元素<目标值，说明这一列其他的元素有可能是目标值，向下移动一行

终止条件:  找到了目标元素  或者 行或列越界

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) and len(matrix[0]): #特判一下矩阵为空的情况
            row = 0
            col = len(matrix[0]) - 1
            while row != len(matrix) and col != -1:
                if matrix[row][col] > target:
                    col -= 1
                elif matrix[row][col] < target:
                    row += 1   
                else:
                    return True
            return False
        else:
            return False

```