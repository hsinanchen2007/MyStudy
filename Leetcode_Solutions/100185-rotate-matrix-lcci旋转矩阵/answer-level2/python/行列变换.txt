### 解题思路
简单找了一下规律，以`[[1,2,3],[4,5,6],[7,8,9]]`为例。

原数组为
```
1   2   3
4   5   6
7   8   9
```
转换后应该是

```
7   4   1
8   5   2
9   6   3
```
稍微观察一下就可以发现，这不就是**行变列，列变行，然后*列*倒序排列**了一下嘛！

拿4行的验证一下

原数组为
```
1   2   3   4
5   6   7   8
9   10  11  12
13  14  15  16  
```
先行列变换：
```
1   5   9   13
2   6   10  14
3   7   11  15
4   8   12  16
```
然后，列倒序排列
```
13   9   5   1
14   10  6   2
15   11  7   3
16   12  8   4
```
刚好是正确答案。

写代码的时候，最后列倒序不好操作，所以在行列变换前，先把行逆序排列，就等价于后面的列逆序了。




### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        if N < 2:
            return matrix
        matrix.reverse()
        for i in range(N):
            for j in range(i, N):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        

```