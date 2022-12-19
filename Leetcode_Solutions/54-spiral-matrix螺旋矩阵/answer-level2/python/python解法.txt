### 解题思路
标记矩阵中每个元素是否已经输出，顺时针共四个方向，每次等到触壁就改变方向，所有元素都标记后退出循环，
![EIE7\]SH_DOYK@PIFQW5NY81.png](https://pic.leetcode-cn.com/f511b23186990d014f19553e17353588203ba6ac0bb866b78ce52f8ae76f3df1-EIE7%5DSH_DOYK@PIFQW5NY81.png)
作为新手代码不太美观，见谅
### 代码

```python
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return matrix
        if len(matrix) == 1:
            return matrix[0]
        res = []
        ans = [[0 for _ in range(len(matrix[0]))] for __ in range(len(matrix))]
        direction = [(0,1), (1, 0), (0, -1),(-1,0)]
        i = 0
        x, y = 0, 0
        tag = i % 4
        dir = direction[tag]
        while ans != [[1]*len(matrix[0])]*len(matrix):  # 未全标记上
            while ans[x][y] == 0:  # 当前点未标记
                ans[x][y] = 1  # 标记该点
                res.append(matrix[x][y])
                x += dir[0]
                y += dir[1]
                if x >= len(matrix) or y >= len(matrix[0]) or x<0 or y<0 or ans[x][y] == 1:  # 出现越界
                    x -= dir[0]
                    y -= dir[1]
                    break
            i += 1
            tag = i%4
            dir = direction[tag]
            x += dir[0]
            y += dir[1]
        return res
```