应该还可以优化一下。。。
懒得直接实现并查集， 模拟了一下

```
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if grid == []:
            return 0
        m, n = len(grid), len(grid[0])
        parents = [[0] * n for i in range(m)]

        def get_parents(i, j):      # 用一个序对模拟。。。
            p = parents[i][j]
            while p != (i, j):
                i, j = p
                p = parents[i][j]
            return p

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    upside = grid[i-1][j] == '1' if i != 0 else False
                    left = grid[i][j-1] == '1' if j != 0 else False
                    if upside:
                        parents[i][j] = get_parents(*parents[i-1][j])
                    elif left:
                        parents[i][j] = get_parents(*parents[i][j-1])
                    if left and upside and get_parents(*parents[i-1][j]) != get_parents(*parents[i][j-1]):
                        p = get_parents(*parents[i][j-1])
                        parents[p[0]][p[1]] = get_parents(*parents[i-1][j])
                    if not upside and not left:
                        parents[i][j] = (i, j)
        s = set()
        for i in range(m):
            for j in range(n):
                if parents[i][j] != 0:
                    s.add(get_parents(*parents[i][j]))
        return len(s)


if __name__ == "__main__":
    s = Solution()
    land = [["1", "1", "1", "1", "0"],
            ["0", "0", "1", "0", "0"],
            ["1", "1", "1", "1", "0"],
            ["0", "0", "0", "0", "0"]]
    print(s.numIslands(land))
```