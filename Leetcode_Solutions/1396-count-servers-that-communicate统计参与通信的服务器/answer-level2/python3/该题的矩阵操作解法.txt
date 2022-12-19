这道题目想来想去也没什么更快的解法，但可以通过非for循环，而是通过矩阵操作来得到结果。
其实矩阵操作并不会更快，本质上还是要遍历访问的。但矩阵操作很多时候是可以优化的，更重要的是，在deeplearning场景下的编程，矩阵操作可以放在gpu上运算，而不需要再cpu上for循环，会快很多。
所以这里以numpy为工具提供矩阵操作的解法。

思路上比较简单： 服务器总数 - 无法通信的服务器数
无法通信的服务器节点有这样的几个特征：
1. 该cell有服务器
2. 该cell所处的row只有一台服务器
3. 该cell所处的col只有一台服务器

所以对于原先的数组，将只有一台服务器的row的所有cell+1，再将只有一台服务器的col的所有cell+1，满足上述条件的cell的值即为3.统计所有值为3的cell的数量即为无法通信的服务器数。（该过程也可以用bool运算完成）

代码如下：

```
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        # m = len(grid)
        # n = len(grid[0])
       
        # row_s = [0 for i in range(m)]
        # col_s = [0 for j in range(n)]

        # for i in range(m):
        #     for j in range(n):
        #         if grid[i][j] > 0:
        #             row_s[i] += 1
        #             col_s[j] += 1

        # ans = 0
        # for i in range(m):
        #     for j in range(n):
        #         if grid[i][j] > 0 and (row_s[i] > 1 or col_s[j] > 1):
        #             ans += 1

        # return ans

        import numpy as np
        array = np.array(grid)

        all_s = array.sum()
        row_s = array.sum(1)
        col_s = array.sum(0)

        array[row_s == 1, :] += 1
        array[:, col_s == 1] += 1

        return all_s - (array == 3).sum()
```
