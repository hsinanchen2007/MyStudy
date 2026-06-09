### 解题思路
仔细分析一下可知，任何一个格子，如果他的相邻的上面和左边的格子都不符合条件的话，那么这个格子和[0][0]格就不是相连的，也即这个格子是机器人走不到的格子。

那么就可以直接初始化mxn矩阵所有值为1，然后开始判定，不符合条件的修改为零，同时累加，最终的值即为答案。

思考了一下，空间使用应该可以进一步优化，也即优化为2xm或者2xn，取小值，因为每个格子只需要根据他相邻的上面一格和左边一格的值来判定，所以只需要缓存两行或者两列的值就可以，不需要存储整个矩阵。不过这样每循环一行或者一列后把当前列赋值给上一列，时间复杂度又提高了大概一倍，看怎么取舍了。


### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        matrix = [[1]*n for _ in range(m)]
        result = 0
        for i in range(m):
            for j in range(n):
                sumall = sum([int(a) for a in str(i)]) + sum([int(b) for b in str(j)])
                if sumall>k:
                    matrix[i][j] = 0

                if i==0 and j==0:
                    matrix[i][j] = 1
                elif i==0 and matrix[i][j-1]==0:
                    matrix[i][j] = 0
                elif j==0 and matrix[i-1][j]==0:
                    matrix[i][j] = 0
                elif matrix[i][j-1]==0 and matrix[i-1][j]==0:
                    matrix[i][j] = 0
                result += matrix[i][j]
        return result
```