# bfs
```
class Solution:
    def __init__(self):
        self.s=0
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        queue = Queue()

        def f(i, j):
            if i>=0 and i<n and j>=0 and j<m and grid[i][j] :
                grid[i][j] = 0
                return True
            return False

        def bfs(i, j):

            if f(i - 1, j):
                self.s += 1
                queue.put([i - 1, j])
            if f(i, j - 1):
                self.s += 1
                queue.put([i, j - 1])
            if f(i + 1, j):
                self.s += 1
                queue.put([i + 1, j])
            if f(i, j + 1):
                self.s += 1
                queue.put([i, j + 1])


        visit = []
        n = len(grid)
        m = len(grid[0])
        for i in range(n):
            visit.append([1 for _ in range(m)])
        maxArea=0
        for i in range(n):
            for j in range(m):
                if f(i,j):
                    self.s=1
                    queue.put([i,j])
                    while not queue.empty():
                        l=queue.get()

                        bfs(l[0],l[1])

                    if self.s>maxArea:
                        maxArea=self.s
        return maxArea
```
