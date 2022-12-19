这道题应该蛮高频的，看过wish和facebook的面经都出现过原题。

只要认真推理一下，不难发现，顺时针rotate90度：$matrix[i][j]$->$matrix[j][n-i]$ 。那我们把这个过程拆分成两步：
- transpose：$matrix[i][j]$->$matrix[j][i]$
- reverse: $matrix[j][i]$->$matrix[j][n-i]$


```python []
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if len(matrix) == 0 or len(matrix) == 1:
            return 
        
        n = len(matrix)
        
        # transpose
        for i in range(n):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # reverse
        for i in range(n):
            for j in range(int(n/2)):
                matrix[i][j], matrix[i][n-j-1] = matrix[i][n-j-1], matrix[i][j]
```
```
复杂度分析：
时间复杂度: O(n2)
空间复杂度: O(1)
```
