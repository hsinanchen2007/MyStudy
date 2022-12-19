### 解题思路

同习题 [73. 矩阵置零](https://leetcode-cn.com/problems/set-matrix-zeroes/)

简单题，首先记录所有 0 元素的下标(i,j)
然后对 (i,j) 分别处理。

但是为了不利用额外的空间，
1. 利用空间 O(mn)
2. 利用空间 O(m+n) 只记录对应的行列下标
3. 利用空间 O(1) 设置一个标志位，对 python, 可以设置字符串， object()。 但对于 java 语言强类型，标志位必须是 int, 可以采用查找[41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)来做,可能会出问题，例如矩阵中所有 int 值都出现过一次。


### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        if m>0:
            n = len(matrix[0])
        else:
            return 
        entry = []
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    entry.append([i,j])
        for (i, j) in entry:
            matrix[i] = [0]*n
            for k in range(m):
                matrix[k][j] = 0
```