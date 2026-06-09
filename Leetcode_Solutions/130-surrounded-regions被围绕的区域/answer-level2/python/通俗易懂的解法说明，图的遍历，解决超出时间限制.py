### 解题思路
本题本质上是图的遍历，深度、广度都行
首先是最容易想到的：
1、遍历每个点
    1.1如果是'X'，跳过
    1.2如果是'O'，执行<2>
2、遍历所有相邻的'O'
    2.1如果没有'O'位于边界中，则全部替换为'X'
    2.2如果有有'O'位于边界，则什么都不做
此思路正确，但是在提交代码过程会出现“运行超出时间限制”
主要原因有二：
a、做了重复的遍历，在上述2的搜索过程中遍历过的点，在上述1的的循环中又再次被遍历。
b、做了无用的遍历，在上述2.2中。

解决：
A、记录遍历过的点（只记录2中的点在循环1中跳过，还是超时间，所以必须进行B）
B、改进思路

新思路：
1、只对二维数组边缘的点进行遍历
    1.1如果不是O，什么都不做
    1.2如果是O，则进行图的遍历，将所有O都转写为T（这些T就是答案中的O）
2、遍历整个数组
    2.1将O转写为X，因为这些O都是与边界不相连的
    2.2将T转写为O，这些是之前与边界相连的O




执行用时 : 44 ms , 在所有 Python 提交中击败了 88.15% 的用户
内存消耗 : 16.7 MB , 在所有 Python 提交中击败了 100.00% 的用户

### 代码

```python
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        for i in range(0, len(board)):
            for j in range(0, len(board[i])):
                if i == 0 or i == len(board) - 1 or j == 0 or j == len(board[i]) - 1:
                    if board[i][j] == 'O':
                        self.bfs_region(board, i, j)
        for i in range(0, len(board)):
            for j in range(0, len(board[i])):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == 'T':
                    board[i][j] = 'O'

    def bfs_region(self, board, i, j):
        queue = [(i, j)]
        visited = set()
        while queue:
            region = queue[0]
            queue = queue[1:]
            board[region[0]][region[1]] = 'T'
            for adjacent in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                next_i, next_j = region[0] + adjacent[0], region[1] + adjacent[1]
                if -1 < next_i < len(board) and -1 < next_j < len(board[next_i]) and board[next_i][next_j] == 'O':
                    if (next_i, next_j) not in visited:
                        visited.add((next_i, next_j))
                        queue.append((next_i, next_j))
```