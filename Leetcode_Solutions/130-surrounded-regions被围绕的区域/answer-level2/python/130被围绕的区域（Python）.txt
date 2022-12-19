这一题的主要思想就是深度遍历搜索法。其实题目就是要我们区分开两种情况：
```
1. 如果给定区域的边缘行列中出现了“O”，并且有“O”与其相连，则连接的“O”区域不能被替换成“X”
2. 如果在给定区域内部中出现了连续的“O”，并且其周围都被“X”包围，则该“O”区域可被替换成“X”
```
两种情况其实只要我们找出了一种情况，并且能把它成功替换，另外一种就好解决了。此题中是想先找出第一种情况，可从给定区域的四周依次往中间遍历，即第一行，第一列，最后一行以及最后一列。之所以要这么麻烦，是考虑到连续的“O”区域可能有好几块，相互不贯通，所以得从四个维度去遍历，避免漏选。如下图所示：
![16dee78a1ffa654bcc907a678417111.jpg](https://pic.leetcode-cn.com/af484cd325bf327ea9c2c18cf823d1784f8c5551d28e9ae1a5c0f9bfefc6befa-16dee78a1ffa654bcc907a678417111.jpg)
因为第一种情况下的“O”是不需要被替换成“X”的，所以为了标记它们，我们得把它们先替换成“*”，最后遍历区域的时候再把它们替换成“O”

代码如下：
```Python
class Solution(object):
    # 可使用深度优先搜索（DFS）求解
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        # 判断给定区域是否为空
        if len(board) ==0 or len(board[0]) == 0:
            return
        # 获取行列值
        rows = len(board)
        cols = len(board[0])
        # 从第一列和最后一列依次往中间做深度遍历，看区域中是否有与边缘列相连的"0"
        # 如果存在这样的"0"，将其变成"*"，最后我们是要将其变成"0"的
        for row in range(rows):
            self.dfs(board, row, 0)
            self.dfs(board, row, cols-1)
        for col in range(cols):
            self.dfs(board, 0, col)
            self.dfs(board, rows-1, col)
        # 标记为"*"的就要重新变成"0"了，仍然为"0"的则要变成"X"了
        for row in range(rows):
            for col in range(cols):
                if board[row][col] == "*":
                    board[row][col] = "O"
                elif board[row][col] == "O":
                    board[row][col] = "X"

    # 深度遍历搜索
    def dfs(self, board, row, col):
        if row not in range(0,len(board)) or col not in range(0,len(board[0])) or board[row][col] != "O":
            return
        board[row][col] = "*"
        # 遍历上下左右四个方向
        self.dfs(board, row-1, col)
        self.dfs(board, row, col+1)
        self.dfs(board, row+1, col)
        self.dfs(board, row, col-1)

if __name__ == "__main__":
    board = [["X","X","X","X"], ["X","O","O","X"],
             ["X","X","O","X"], ["X","O","X","X"]]
    Solution().solve(board)
```
不过执行效率比较低，在10%左右，看了网上大佬的解法，好像都是这样，有些奇怪。
![6aa5355939cc9db64553c6fefc0cca9.png](https://pic.leetcode-cn.com/c1686409cb83008db74489da3427da6326980144eb48cb2adbe6aa613f847b6c-6aa5355939cc9db64553c6fefc0cca9.png)