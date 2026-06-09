### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if len(matrix) < 2: return 


        def change(bg, end, depth):
            if not bg < end:
                return
            for i in range(bg, end):
                matrix[bg][i], matrix[i][end], matrix[end][end-i+depth], matrix[end-i+depth][bg] = matrix[end-i+depth][bg], matrix[bg][i], matrix[i][end], matrix[end][end-i+depth]
            change(bg+1, end-1, depth+1)


        n = len(matrix)
        change(0,n-1,0)
```