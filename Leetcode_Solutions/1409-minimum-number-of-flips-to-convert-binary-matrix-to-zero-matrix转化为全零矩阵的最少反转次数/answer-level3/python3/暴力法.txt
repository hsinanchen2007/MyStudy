输入矩阵的大小不会很大，所以完全可以通过暴力的方式来处理。
如果对同一个位置执行了两次reverse操作，相当于没有执行任何操作（我承认我是看了提示才意识到这一点的），所以，在m*n个位置中选若干个位置执行reverse操作即可。
用深度优先搜索，写得很烂，我是菜鸡……

```python
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        m = len(mat)
        if m == 0:
            return 0
        n = len(mat[0])
        if n == 0:
            return 0
        mat_code = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    mat_code = mat_code ^ (1 << (i * n + j))
        if mat_code == 0:
            return 0
        ret = self.dfs(mat_code, 0, 0, m, n, 0)
        if ret > m * n:
            return -1
        else:
            return ret

    def dfs(self, mat_code, i, j, m, n, previous_step_number):
        new_code = self.reverse(mat_code, i, j, m, n)
        if new_code == 0:
            return previous_step_number + 1
        else:
            ni, nj = self.next_pos(i, j, m, n)
            if ni is None or nj is None:
                return m * n + 1
            return min(
                self.dfs(new_code, ni, nj, m, n, previous_step_number + 1),
                self.dfs(mat_code, ni, nj, m, n, previous_step_number)
            )

    def next_pos(self, i, j, m, n):
        val = i * n + j + 1
        if val >= m * n:
            return None, None
        return val // n, val % n

    def reverse(self, mat_code, i, j, m, n):
        mat_code = mat_code ^ 1 << (n * i + j)
        if i > 0:
            mat_code = mat_code ^ 1 << (n * i - n + j)
        if i + 1 < m:
            mat_code = mat_code ^ 1 << (n * i + n + j)
        if j > 0:
            mat_code = mat_code ^ 1 << (n * i + j - 1)
        if j + 1 < n:
            mat_code = mat_code ^ 1 << (n * i + j + 1)
        return mat_code
```
