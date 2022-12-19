![image.png](https://pic.leetcode-cn.com/cdb3efa0abf5695f67798681c4deb1449067351064b0704bfd4970c98f0122a7-image.png)


```
'''
朴素模拟数据填写即可
'''

from typing import List
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])

        pos = [(0,0)]
        for i in range(1, m):
            pos.append((i, 0))
        for j in range(1, n):
            pos.append((0, j))

        for i, j in pos:
            ii, jj = i, j

            val = []
            while ii < m and jj < n:
                val.append(mat[ii][jj])
                ii, jj = ii+1, jj+1
            val.sort()

            ii, jj = i, j
            idx = 0
            while ii < m and jj < n:
                mat[ii][jj] = val[idx]
                ii, jj, idx = ii+1, jj+1, idx+1

        return mat
```
