python DFS操作
我感觉主要麻烦的点是怎么在DFS里面存访问过的点
我用的集合存储访问过的点, 构造nonlocal 变量来进行类似的剪枝操作

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not word or not board:
            return False
        n = len(word)
        row, col = len(board), len(board[0])
        visited = set() # 集合存储访问过的点
        res = False

        def dfs(i, j, idx):
            nonlocal res # res 就是是否访问成功
            if i in [-1, row] or j in [-1, col] or board[i][j] != word[idx]:
                """
                如果超出矩阵索引或者当前位置的值不正确,直接返回
                """
                return
            if (i, j) in visited:
                # 如果当前的点已经被访问过了,直接返回
                return
            if board[i][j] == word[idx]: # 当前的点正确
                if idx == n - 1:#当前的点就是word最后一个字母,那搜索成功了
                    res = True
                    return
                # 如果不是最后一个字母,搜索部分成功,将当前点加入visited
                visited.add((i, j))
                for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    # 进入dfs, 使用res作为短路的条件
                    # 如果已经搜索成功了, 那就不需要在继续dfs了
                    if not res:
                        dfs(i + di, j + dj, idx + 1)
                # 至此四个方向都搜索完, 如果没有成功
                # 系统出栈, 应该把当前点从visited里面删去
                visited.remove((i, j))

        for i in range(row):
            for j in range(col):
                if board[i][j] == word[0]:
                    dfs(i, j, 0)
                if res: return True
        return False
```