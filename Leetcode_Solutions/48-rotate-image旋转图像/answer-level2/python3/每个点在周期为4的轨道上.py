坐标为(i,j) , (j, n-i), (n-i, n-j), (n-j, i)的进行轮换。（这里的n是len(matrix)-1)

只要对(i,j)在四分之一个方形内遍历即可。

需要注意的是，如果边长为奇数，要保证各边中垂线上的点恰好被轮换一次，i，j的循环长度稍稍不等。
至于最中心倒是无所谓。

```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        lm=len(matrix)-1
        for i in range((lm)//2+1):
            for j in range((lm+1)//2):
                temp=matrix[i][j]
                matrix[i][j]=matrix[lm-j][i]
                matrix[lm-j][i]=matrix[lm-i][lm-j]
                matrix[lm-i][lm-j]=matrix[j][lm-i]
                matrix[j][lm-i]=temp
        return
```