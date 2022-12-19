## 分析
N皇后问题是一个非常经典的深度搜索的问题。他的递归搜索树如下图所示：
![1558653932669.png](https://pic.leetcode-cn.com/091812df088effe0e9927b9ae360a9b6a5ba94decbd86a140d2d626e42af96e5-1558653932669.png)

它的最重要的一点就是我们如何快速的判断不合法的情况。
首先明确不合法的情况有：
- 同一行不能有两个皇后：能在递归参数层面直接解决。
- 同一列不能有两个皇后：使用一个标记数组标记当前列是否被占用。
- 同一个对角线不能有两个皇后：
	- 对角线1：用一个标记数组表示第i对角线1被占用
	- 对角线2：用另一个标记数组表示第i对角线2被占用

这里最复杂的应该是对角线被占用的表示问题了，我们来看一下一种简便的表示方法：
对于对角线1如下图所示：
![1558654451062.png](https://pic.leetcode-cn.com/8ac8df75ba03e49011af1ebdc4a7e37d7c40985f910a7058cc5f6784f3d7e5a3-1558654451062.png)

它一共有2*n-1个，并且每一条对角线i+j都是相等的。
对于对角线2如下图所示：
![1558654551703.png](https://pic.leetcode-cn.com/73f723d6acf2b684e9cd41815ccd09574bb1c20f2b416388b2d0fe2a7514b302-1558654551703.png)
同样也有2*n-1个，它的规律是每一条对角线上两个元素相减是相等的，但是为了让它的结果能在0-2*n-1之间，所以我们使用i-j+n-1。
判断好了这几点，所以我们可以快速的写出答案了。



## 答案
```python
class Solution:
    def __init__(self):
        # 列的标记数组
        self.cols = None
        # 对角线1的标记数组
        self.dia1 = None
        # 对角线2的标记数组
        self.dia2 = None
        # 最终结果
        self.result_all = None

    def solveNQueens(self, n: int):
        # 初始化一些数据
        self.cols = [0] * n
        self.dia1 = [0] * (2 * n - 1)
        self.dia2 = [0] * (2 * n - 1)
        self.result_all = []
        # 深度搜素
        self.dfs(n, 0, [])
        final_result = []
        for res in self.result_all:
            s = []
            for i, j in res:
                s_row = ["."] * n
                s_row[j] = 'Q'
                s.append("".join(s_row))
            final_result.append(s)
        return final_result

    def dfs(self, n, x, result):
        if x == n:
            self.result_all.append(result[:])
            return

        for y in range(n):
            if self.cols[y] == 1 or self.dia1[x + y] == 1 or self.dia2[x - y + n - 1] == 1:
                continue
            self.cols[y] = 1
            self.dia1[x + y] = 1
            self.dia2[x - y + n - 1] = 1
            result.append((x, y))
            self.dfs(n, x + 1, result)
            self.cols[y] = 0
            self.dia1[x + y] = 0
            self.dia2[x - y + n - 1] = 0
            result.pop()
        return
```






