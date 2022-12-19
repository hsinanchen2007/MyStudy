
1.  顺时针就是先转置再水平翻转
1.  这样子点(i,j)--转置-->点(j,i)--水平翻转-->点(j,n-1-i)
1.  旋转的本质是4个数的轮换，上边分析得到点(i,j)旋转到点(j,n-1-i)，那么继续按照2往后推：
      1. 点(j,n-1-i)--转置-->(n-1-i,j)--水平翻转-->(n-i-1,n-j-1)
      2. 点(n-i-1,n-j-1)--转置-->(n-j-1,n-i-1)--水平翻转-->(n-j-1,i)
      3. 点(n-j-1,i)--转置-->(i,n-j-1)--水平翻转-->(i,j)
所以任意点(i,j)的轮换路径为(i,j),(j,n-1-i),(n-1-i,n-1-j),(n-1-j,i)
那么就可以根据这个写代码了

```python []
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        A = matrix
        n = len(A)
        for i in range(n//2):
            for j in range(n-n//2):
                A[i][j], A[n-1-j][i], A[n-1-i][n-1-j], A[j][n-1-i] = \
                          A[n-1-j][i], A[n-1-i][n-1-j], A[j][n-1-i], A[i][j]
```

