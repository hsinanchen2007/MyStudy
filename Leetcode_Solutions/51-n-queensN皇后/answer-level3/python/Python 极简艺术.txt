代码太长，人都晕了，参考于liweiwei1419，给大伙简化代码
```
class Solution(object):
    def solveNQueens(self, n):
        res = []
        if n == 0: return res
        # row为当前行，col为不可再使用的列，master为不可再使用的主对角线，slave为不可再使用的副对角线
        def dfs(row, col, master, slave, cur_res):
            if row == n:
                res.append(["." * cur + "Q" + "." * (n - cur - 1) for cur in cur_res])
                return
            for i in range(n):
                if (i not in col) and (i+row not in slave) and (i-row not in master):
                    dfs(row+1, col|{i}, master|{i-row}, slave|{i+row}, cur_res+[i])

        dfs(0, set(), set(), set(), [])
        return res
```
