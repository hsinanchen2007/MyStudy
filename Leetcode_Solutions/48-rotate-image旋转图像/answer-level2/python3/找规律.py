![捕获1.PNG](https://pic.leetcode-cn.com/1ee7530cbccb9546f21616ce9f70a644e5ace0c5c71db25940cd1f25df298a67-%E6%8D%95%E8%8E%B71.PNG)

```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        matrix[:]=[[matrix[i][j] for i in range(n-1,-1,-1)] for j in range(0,n)]
```
