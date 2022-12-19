为什么我用deepcopy的内存消耗比就地算法的内存消耗更小呢？

![image.png](https://pic.leetcode-cn.com/395b1da0946e6eecc7d3276c046a2d548e979625fdb6a0c7c5af79555b73c6fe-image.png)

以下为deepcopy写法

```
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        ans = copy.deepcopy(board)

        def live_num_around(board, i, j):
            rs = 0
            for x, y in [(i-1, j-1), (i-1, j), (i-1, j+1), (i, j-1), (i, j+1), (i+1, j-1), (i+1, j), (i+1, j+1)]:
                if x < len(board) and x >= 0 and y >= 0 and y < len(board[0]):
                    rs += board[x][y]
            return rs

        for i, row in enumerate(board):
            for j, e in enumerate(row):
                n = live_num_around(board, i, j)
                #print("element(%s,%s) 's around live num is: %s" % (i, j, n))
                if e == 1:
                    if n < 2 or n > 3:
                        ans[i][j] = 0
                    elif n == 2 or n == 3:
                        ans[i][j] = 1
                if e == 0:
                    if n == 3:
                        ans[i][j] = 1
                    else:
                        ans[i][j] = 0
        
        for i, row in enumerate(board):
            for j, e in enumerate(row):
                board[i][j] = ans[i][j]

```

以下为就地写法，将board中数字的10位数字来保存周围活细胞数量

```
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def live_num_around(board, i, j):
            rs = 0
            for x, y in [(i-1, j-1), (i-1, j), (i-1, j+1), (i, j-1), (i, j+1), (i+1, j-1), (i+1, j), (i+1, j+1)]:
                if x < len(board) and x >= 0 and y >= 0 and y < len(board[0]):
                    #由于用十位数保存已经计算的周边个数，这里必须%10
                    rs += board[x][y] % 10
            return rs

        #先遍历一遍board,将每个元素周边活细胞个数计算出来，存到这个细胞的十位数上（因为最多8，十位数上0-9够了）
        for i, row in enumerate(board):
            for j, e in enumerate(row):
                n = live_num_around(board, i, j)
                board[i][j] += 10*n
        #再遍历一遍board（每个元素除10，取整为周边个数，取余为死活状态）根据规则将对应元素写0/1
        for i, row in enumerate(board):
            for j, e in enumerate(row):
                n, status = divmod(board[i][j], 10)
                #print("element(%s,%s) 's around live num is: %s , status=%s" % (i, j, n, status))
                if status == 1:
                    if n < 2 or n > 3:
                        board[i][j] = 0
                    elif n == 2 or n == 3:
                        board[i][j] = 1
                if status == 0:
                    if n == 3:
                        board[i][j] = 1
                    else:
                        board[i][j] = 0
```
