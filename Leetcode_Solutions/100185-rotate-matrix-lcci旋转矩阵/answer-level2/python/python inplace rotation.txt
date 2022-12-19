### 解题思路
执行用时 :
32 ms
, 在所有 Python3 提交中击败了
94.03%
的用户
内存消耗 :
13.7 MB
, 在所有 Python3 提交中击败了
100.00%
的用户

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        n = N-1
        if N % 2 == 0:
            num = int(N/2)
            for i in range(num):
                for j in range(num):
                    matrix[i][j], matrix[j][n-i] = matrix[j][n-i], matrix[i][j]
                    matrix[i][j], matrix[n-i][n-j] = matrix[n-i][n-j], matrix[i][j]
                    matrix[i][j], matrix[n-j][i] = matrix[n-j][i], matrix[i][j]
        else:
            num = int((N+1)/2)
            for i in range(num-1):
                for j in range(num):
                    matrix[i][j], matrix[j][n-i] = matrix[j][n-i], matrix[i][j]
                    matrix[i][j], matrix[n-i][n-j] = matrix[n-i][n-j], matrix[i][j]
                    matrix[i][j], matrix[n-j][i] = matrix[n-j][i], matrix[i][j]

        
        # for i in range(num):
        #     for j in range(num):
        #         matrix[i][j], matrix[j][n-i] = matrix[j][n-i], matrix[i][j]
        #         matrix[i][j], matrix[n-i][n-j] = matrix[n-i][n-j], matrix[i][j]
        #         matrix[i][j], matrix[n-j][i] = matrix[n-j][i], matrix[i][j]
```