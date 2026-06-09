## 成绩（2019.07.10）
执行用时 :48 ms, 在所有 Python3 提交中击败了99.25%的用户

内存消耗 :12.9 MB, 在所有 Python3 提交中击败了100.00%的用户

## 实现
思路就不必说了，三个面的投影计算方法:

1. 矩阵中有几个不为零的值
2. 矩阵中按行取最大值相加
3. 矩阵按列取最大值相加

用循环较慢，所以用列表推导式

```Python
class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        xy = sum([sum([1 if j else 0 for j in i]) for i in grid]) #m*n
        xz = sum([max(i) for i in grid]) # m*1
        yz = sum([max([grid[i][j] for i in range(m)]) for j in range(n)]) #n*1
        #print(xy, xz, yz)
        return xy+xz+yz
```

可以把三个面的面积计算写成一行，那样快一点点，相当于少了两个赋值的过程。
按列求最大值我用了行数和列数辅助，没有费心思去想怎么直接用矩阵算