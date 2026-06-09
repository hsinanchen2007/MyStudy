```
class Solution:
    def __init__(self):
        self.count = 0
    
    def movingCount(self, m: int, n: int, k: int) -> int:
        marked = [[0 for _ in range(n)] for _ in range(m)]
        self.__bfs_search(0, 0, k, marked)
        return self.count

    def __bfs_search(self, x, y, k, marked):
        if 0 <= x < len(marked) and 0<= y < len(marked[0]):
            num1 = list(map(int, str(x)))
            num2 = list(map(int, str(y)))
            if sum(num1) + sum(num2) <= k and marked[x][y] == 0:
                self.count += 1
                marked[x][y] = 1
                self.__bfs_search(x + 1, y, k, marked)
                self.__bfs_search(x, y + 1, k, marked)

        return
```
