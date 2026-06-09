## **旋转90度实际上只需要两个步骤。**
# 1上下反转整个矩阵
# 2然后再对角线反转
所以我们假设n*n矩阵中的一个数字为[i][j]
因为**上下翻转列数不变**，而且**反转过后和反转之前的行数相加等于n-1**（记住数组从0开始）
那么上下翻转过后他就是[n-i-1][j]

接着就是对角线反转，这个很简单就不解释了，反转之后就是[j][n-i-1]
由此我们可以根据原理写出代码
```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        matrix[::]=matrix[::-1]  //先上下翻转
        for i in range(n):
            for j in range(i,n):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]//对角线翻转

```
代码也可以用如下形式写，依据就是本文开始的公式，只需要连续对四个值复制就是完成90度翻转了。有兴趣的可以看看。
`
``class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        for i in range(n//2):
            for j in range(i,n-i-1):
                matrix[j][n-i-1],matrix[n-i-1][n-j-1],matrix[n-j-1][i],matrix[i][j]=matrix[i][j],matrix[j][n-i-1],matrix[n-i-1][n-j-1],matrix[n-j-1][i]`

```


