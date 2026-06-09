### 解题思路
就回溯法. 注意的是grid里存的是str! 不是int
而mask没必要用! 直接在原数组上做标记, 省去O(n^2)的空间

### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        def solve(i, j, mask, grid, h, w):
            if i<0 or i>=h or j<0 or j>=w or grid[i][j]=='0' or mask[i][j]:
                return
            mask[i][j] = 1
            solve(i+1, j, mask, grid, h, w)
            solve(i-1, j, mask, grid, h, w)
            solve(i, j+1, mask, grid, h, w)
            solve(i, j-1, mask, grid, h, w)

        h, w = len(grid), len(grid[0])
        mask = [[0]*w for _ in range(h)]
        res = 0
        for i in range(h):
            for j in range(w):
                if mask[i][j] or grid[i][j]=='0':
                    continue
                solve(i, j, mask, grid, h, w)
                res += 1
        return res
```

并查集也可以再复习下, 不过并查集貌似需要额外的空间
三个操作
find(int m)：这是并查集的基本操作，查找 mm 的根节点。

isConnected(int m,int n)：判断 m，nm，n 两个点是否在一个连通区域。

union(int m,int n):合并 m，nm，n 两个点所在的连通区域。
