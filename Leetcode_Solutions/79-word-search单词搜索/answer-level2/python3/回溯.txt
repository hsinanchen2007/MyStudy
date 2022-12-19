### 解题思路
遍历每一个位置，开始回溯，在回溯过程中，一条路径中，访问过的节点标记为1，下一次不再访问，但若已经切换为另一条路径，则需要把之前标记为1的节点变为原始字符

### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # 回溯
        def dfs(i, j, word):
            if not word:return True
            for x, y in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                if (0 <= i + x < len(board) and 0 <= j + y < len(board[0])) and (board[i + x][j + y] == word[0] and board[i + x][j + y] != 1):
                    tmp_ = board[i + x][j + y]
                    board[i + x][j + y] = 1
                    if dfs(i + x, j + y, word[1:]):
                        return True
                    else:
                        board[i + x][j + y] = tmp_

            return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    tmp = board[i][j]
                    board[i][j] = 1
                    if dfs(i, j, word[1:]):
                        return True
                    else:
                        board[i][j] = tmp
        return False

            
                


```