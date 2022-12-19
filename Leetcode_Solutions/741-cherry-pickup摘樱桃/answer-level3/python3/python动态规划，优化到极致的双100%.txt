![image.png](https://pic.leetcode-cn.com/5c3d4e3ab8cb4f526e59276fc53de1b20acc1034d426292815eb1d6b6de9d8dd-image.png)
```python
    def cherryPickup(self, grid: list) -> int:
        N = len(grid)  # 转化为2人同时从(0,0)走到(N-1,N-1)的最大收益
        S = (N-1) << 1  # 最大步数，即（N-1)*2步走到目的地
        dp = {(0, 0, 0): grid[0][0]}  # dp[s,i,j]走了s步且位于两人分别位于i,j两行的最大收益，在下面的循环里仅当(s,i,j)状态可达时才存入哈希
        moves = ((0, 0), (1, 0), (0, 1), (1, 1))  # i,j要考虑的上一时刻到现在可能的变化量
        for s in range(1, S+1):  # 逐步考虑
            for y1 in range(min(s+1, N)):
                x1 = s-y1
                if x1 >= N or grid[y1][x1] == -1:  # 该状态不可达
                    continue
                for y2 in range(y1, min(s+1, N)):  # 仅考虑y1<=y2，因为(s,y1,y2)与(s,y2,y1)等价
                    x2 = s-y2
                    if x2 >= N or grid[y2][x2] == -1:  # 该状态不可达
                        continue
                    _max = -1  # -1占位后面判断可达
                    for dy1, dy2 in moves:
                        _y1, _y2 = y1-dy1, y2-dy2  # 其可能来自的状态
                        if _y1 > _y2:
                            continue
                        _max = max(_max, dp.get((s-1, _y1, _y2), -1))
                    if _max != -1:  # 仍为-1则说明没有前置状态可以到达当前状态
                        dp[s, y1, y2] = _max + grid[y1][x1] + grid[y2][x2] if y1 != y2 else _max + grid[y1][x1]  # y1=y2时则只能有一个人获得樱桃
        return dp.get((S, N-1, N-1), 0)  # 若该状态不可达，返回0

```
