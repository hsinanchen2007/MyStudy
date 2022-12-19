### 解题思路

方格求最短路，BFS。(好像一般方格里面走的问题都可以转化为有向图然后遍历等等。。)

时间复杂度`O(N*N)`

### 代码

```python3
class Solution:
    def snakesAndLadders(self, board) -> int:

        def get_index(a):
            # 将树转化为数组中的下标
            row = a // n
            col = a % n
            if row & 1:
                return n - 1 - row, n - 1 - col
            else:
                return n - 1 - row, col

        s = []
        t = []
        s.append(0)
        n = len(board)

        vis = [False] * (n * n + 1)
        vis[1] = True

        s = [1]

        _len = 0
        while len(s):
            for x in s:
                for i in range(1, 7):
                    tmp = i + x
                    if tmp == n * n :
                        return _len + 1
                    else:
                        _i, _j = get_index(tmp - 1)
                        if board[_i][_j] != -1:
                            if board[_i][_j] == n * n:
                                return _len + 1
                            else:
                                if not vis[board[_i][_j]]:
                                    vis[board[_i][_j]] = True
                                    t.append(board[_i][_j])
                        else:
                            if not vis[tmp]:
                                vis[tmp] = True
                                t.append(tmp)
            _len += 1
            s = t
            t = []
        return -1
```