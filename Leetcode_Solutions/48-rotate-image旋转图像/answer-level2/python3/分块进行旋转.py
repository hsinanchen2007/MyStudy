### 解题思路
如果矩阵的size是偶数，可以直接将其分成四块，然后四块（每一块为d//2 * d//2）里对应的四个位置做旋转就可以了，没有多余的操作。
如果矩阵的size是奇数，那么最中间的那一块就不会动，剩下的部分也分成四块，每一块的大小是 d//2 * (d//2+1), 然后做旋转，依然没有多余的操作。
至于每四个对应位置的旋转可以直接借一个数来操作，不过总内存消耗似乎有点大（13.6MB）
不知有没有更好的方案

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        d = len(matrix)
        temp = 0
        for i in range(d//2):
            for j in range(d//2+d%2):
                temp = matrix[i][j]
                matrix[i][j] = matrix[d-1-j][i]
                matrix[d-1-j][i] = matrix[d-1-i][d-1-j]
                matrix[d-1-i][d-1-j] = matrix[j][d-1-i]
                matrix[j][d-1-i] = temp
                
                
                


```