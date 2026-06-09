# 题解
## 直接旋转
![在这里插入图片描述](https://pic.leetcode-cn.com/c2311ec0c475c55eea282b763d8276a6a91e5abdb99d4a4184481da36b8c1932.png)
图像旋转，实际上是这四个位置上的数对应旋转。
因此，需要找到这四个位置索引的相互关系：
$matrix[i][j] \to matrix[j][n-i-1]\to matrix[n-i-1][n-j-1]\to matrix[n-j-1][i]$
**注意两个边界条件**
行只需遍历一半 ，$[0,n//2)$
列需要在$[i,n-i-1)$内


### 复杂度分析
 - 时间复杂度：$O\left(n^{2}\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix) 
        for i in range(n//2):
            for j in range(i, n - i - 1):
                matrix[i][j],matrix[j][n-i-1],matrix[n-i-1][n-j-1],matrix[n-j-1][i] = \
                matrix[n-j-1][i], matrix[i][j],matrix[j][n-i-1],matrix[n-i-1][n-j-1]
```


## 转置矩阵的性质
![在这里插入图片描述](https://pic.leetcode-cn.com/06c5ae7faeb7cb15d2754a7fae95fa4bda341a3ec164aa6334d8159cb5c87444.png)
转置后：
![在这里插入图片描述](https://pic.leetcode-cn.com/d6233e8fae6f8c998ee5f292d9edeae6afa2d96dbc38a50057722af947841dd3.png)
每一行逆序：
![在这里插入图片描述](https://pic.leetcode-cn.com/ad36b5ac291cdcf998bca704e6e808dcb08189361972d6122bc43a92b101db04.png)
**逆置边界条件**

列需要在$[i,n)$内


### 复杂度分析
 - 时间复杂度：$O\left(n^{2}\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        for i in range(n):
            for j in range(i,n):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
        for i in range(n):
            matrix[i].reverse()
```