# 题解
```python
class Solution:
    def totalNQueens(self, n: int) -> int:
        def DFS(n: int, row: int, cols: int, left: int, right: int):
            """ 深度优先搜索
            :param n: N皇后个数
            :param row: 递归的深度
            :param cols: 可被攻击的列
            :param left: 左侧斜线上可被攻击的列
            :param right: 右侧斜线上可被攻击的列
            """
            if row >= n:
                self.res += 1
                return

            # 获取当前可用的空间
            bits = (~(cols | left | right)) & ((1 << n) - 1)

            # 遍历可用空间
            while bits:
                # 获取一个位置
                p = bits & -bits
                DFS(n, row + 1, cols | p, (left | p) << 1, (right | p) >> 1)
                bits = bits & (bits - 1)

        if not (n == 1 or n >= 4):
            # N皇后问题只有在 N 大于等于 4 或等于 1 的时候才有解
            return 0
        self.res = 0
        DFS(n, 0, 0, 0, 0)
        return self.res
```
