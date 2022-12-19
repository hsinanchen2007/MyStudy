### 分析:

本题可以用 `DFS`（深度优先搜索）解决。

找到所有被 `X` 围绕的区域不容易，但是其等价于找到所有没有没有被 `X` 围绕的区域（连接边界的区域），这样就可以从边界上的 `O` 开始进行深度优先搜索，

举个例子：
```
X X X X
X X O X
X O X X
X O X X
```
对于上面这张图的边界，只有第四行第二列的内容是 `O`，我们对其进行 `DFS`，即 `DFS(3,1)`
首先将它本身改为 #
```
X X X X
X X O X
X O X X
X # X X
```
之后对该位置的上下左右进行搜索，即分别尝试 `DFS(2,1)`，`DFS(4,1)`，`DFS(3,0)`，`DFS(3,2)`，如果越界或者内容不是 `O` 则停止搜索。

因为此位置左右是 `X`，下面超出数组下边界，只有上面是 `O`，所以继续进行 `DFS(2,1)`。
```
X X X X
X X O X
X # X X
X # X X
```
和之前一样，先将其本身改为 `#`，之后上下左右进行 `DFS`，而对于此坐标上下左右都不是 `O`，所以搜索结束。

最后遍历全图，将所有的#改为 `O`，所有的 `O` 改为 `X` 即可。

最终结果：
```
X X X X
X X X X
X O X X
X O X X
```
### 代码:
```python [-Python]
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 如果是空数组，直接返回
        # Leetcode总搞这种边边角角的输入
        if not board: return
        # 计算数组长宽
        row = len(board)
        col = len(board[0])
        # 如果长度或者宽度中一个小于3的话也不用算了，直接返回
        if row < 3 or col < 3: return
        # DFS函数
        def dfs(i, j):
        # 如果i，j中有一个越界或者遇到了X则不继续扫描
            if i < 0 or j < 0 or i >= row or j >= col or board[i][j] != 'O':
                return
            # 否则把数组中的O变成#，意思是这个O和边缘是连通的
            board[i][j] = '#'
            # 之后从当前坐标开始上下左右进行递归搜索
            dfs(i - 1, j)
            dfs(i + 1, j)
            dfs(i, j - 1)
            dfs(i, j + 1)
        
        for i in range(row):
        # 搜索第一行和最后一行
            dfs(i, 0)
            dfs(i, col - 1)
        
        for i in range(col):
        # 搜索第一列和最后一列
            dfs(0, i)
            dfs(row - 1, i)

        # 全部搜索完毕后：
        # X X X X 
        # X X O X
        # X O X X
        # X O X X
        # 变为：    
        # X X X X
        # X X O X
        # X # X X
        # X # X X
        # 之后再将所有的#变成O，O变成X就可以了
        for i in range(0, row):
            for j in range(0, col):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == '#':
                    board[i][j] = 'O'
```
---
执行用时 : 140 ms, 在所有 Python3 提交中击败了 98.19% 的用户

内存消耗 : 14.6 MB, 在所有 Python3 提交中击败了 74.24% 的用户