```
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        #弯弯绕绕的棋盘，行分奇数偶数，从下往上数的。。。
        #直接浪费内存转一维数组，空间复杂度o(N^2)
        road = [0] * (n*n)
        for i in range(n):
            if i % 2 == 0:
                for j in range(n):
                    road[n*i+j] = board[n-1-i][j]
            else:
                for j in range(n):
                    road[n*i+j] = board[n-1-i][n-j-1]
        stack = []
        stack.append(0)
        next_step = []
        ans = 1
        res = 0
        #广度优先搜素,时间复杂度o(N^2)
        while ans <= n*n//6+1:
            while stack:
                p = stack.pop()
                res = 0
                while res <= 5:
                    p = p + 1
                    if p == n*n -1:
                        return ans
                    elif road[p] == -1:
                        next_step.append(p)
                        road[p] = -2
                    elif road[p] >= 0 and road[road[p]-1] >= -1:
                        if road[p]-1 == n*n-1:
                            return ans
                        next_step.append(road[p]-1)
                        if road[road[p]-1] == -1:
                            road[road[p]-1] = -2
                    res += 1
            ans += 1
            stack = next_step
            next_step = []
        return -1
```
