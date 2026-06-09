### 解题思路
找好可以移动的矩阵上下左右边界（这个边界是还未被访问的边界）u,d,l,r
定义一个移动方向step
右移：step=(0,1)
下移：step=(1,0)
左移：step=(0,-1)
上移：step=(-1,0)
然后从原点(0,0)开始移动，循环要求(i,j)一直在上下左右边界内
循环终止条件：上下左右边界相等，此时一定是最后一个未访问的点
循环时，不断按照step方向移动，遇到顶点就右转
右转的时候就修改step方向和最新边界


### 代码

```python3
class Solution:
    def spiralOrder(self, matrix):
        if not matrix:
            return []
        res = []
        u, d, l, r = 0, len(matrix) - 1, 0, len(matrix[0]) - 1
        step = (0, 1)
        i = j = 0
        while u <= i <= d and l <= j <= r:
            res.append(matrix[i][j])
            if u == i == d and l == j == r:
                break
            elif step == (-1, 0) and u == i and l == j < r:
                step = (0, 1)
                l += 1
            elif step == (0, 1) and u == i < d and j == r:
                step = (1, 0)
                u += 1
            elif step == (1, 0) and i == d and l < j == r:
                step = (0, -1)
                r -= 1
            elif step == (0, -1) and u < i == d and j == l:
                step = (-1, 0)
                d -= 1
            i, j = i + step[0], j + step[1]
        return res
```