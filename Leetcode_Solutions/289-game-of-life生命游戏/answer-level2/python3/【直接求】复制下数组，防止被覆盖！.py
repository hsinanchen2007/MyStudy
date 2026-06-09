# 题目大意

玩一个生存游戏。这个游戏给了一个二维数组，每个数组上写的是这个地方是否有部落。看每个位置的 8 连通位置的部落数：

1. 如果一个活着的部落，其周围少于2个部落，这个部落会死；
2. 如果一个活着的部落，其周围部落数在2或者3，这个部落活到下一个迭代中；
3. 如果一个活着的部落，其周围多于3个部落，这个部落会死；
4. 如果一个死了的部落，其周围多于3个部落，这个部落会活。

**一次迭代是同时进行的**，求一轮之后，整个数组。

解释下 4 联通和 8 联通：

![image.png](https://pic.leetcode-cn.com/f53809fcb7cae381ae9da2fc8b797a3415f1c45c27b4f8d57b640370b6e9b98d-image.png)

# 解题方法

方法很简单暴力，直接统计每个位置的 8 连通分量并根据部落数进行题目所说的判断就好了。

由于一次迭代是同时进行的，所以不能一边统计一边修改数组，这样会影响后面的判断。我的做法是先把输入的面板复制了一份，这样使用原始的 `board` 去判断部落数，更新放在了新的 `board_next` 上不会影响之前的 `board`。最后再把数值复制过来。

题目给了 4 个存活和死亡的判断条件，直接按照这4个条件判断即可。我定义了一个函数`liveOrDead()`用来判断当前判断的部落应该活还是死，返回结果的解释：0-不变, 1-活下来,2-要死了。

时间复杂度是O(MN)，空间复杂度是O(MN).

Python代码如下：

```python
class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if board and board[0]:
            M, N = len(board), len(board[0])
            board_next = copy.deepcopy(board)
            for m in range(M):
                for n in range(N):
                    lod = self.liveOrDead(board, m, n)
                    if lod == 2:
                        board_next[m][n] = 0
                    elif lod == 1:
                        board_next[m][n] = 1
            for m in range(M):
                for n in range(N):
                    board[m][n] = board_next[m][n]
            
    def liveOrDead(self, board, i, j):# return 0-nothing,1-live,2-dead
        ds = [(1, 1), (1, -1), (1, 0), (-1, 1), (-1, 0), (-1, -1), (0, 1), (0, -1)]
        live_count = 0
        M, N = len(board), len(board[0])
        for d in ds:
            r, c = i + d[0], j + d[1]
            if 0 <= r < M and 0 <= c < N:
                if board[r][c] == 1:
                    live_count += 1
        if live_count < 2 or live_count > 3:
            return 2
        elif board[i][j] == 1 or (live_count == 3 and board[i][j] ==0):
            return 1
        else:
            return 0
```

## 欢迎关注[负雪明烛的刷题博客](https://blog.csdn.net/fuxuemingzhu)，刷题800多，每道都记录了写法！

力扣每日一题活动建群啦，一起监督和讨论，我自建监督网址：[http://group.ojeveryday.com/#/check](http://group.ojeveryday.com/#/check)，加入方式可以在监督网址中看到。

![image.png](https://pic.leetcode-cn.com/cddebf5d29d0715c42576d230c0867cecfc8cd672f1e22cf6bb77061dcfe1a88-image.png)