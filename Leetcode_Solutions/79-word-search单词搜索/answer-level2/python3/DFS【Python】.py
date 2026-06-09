### 思路

**DFS**

```
DFS 四个方向搜索，访问过的标记为 '#' 表示不可重复访问。
记得访问结束要恢复，因为还有其他路径。
```

##### Python3代码

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board:
            return False
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.dfs(board, i, j, word):
                    return True
        return False

    def dfs(self, board, i, j, word):
        if len(word) == 0:
            return True
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or word[0] != board[i][j]:
            return False
        tmp, board[i][j] = board[i][j], '#'  # '#': visited
        ans = self.dfs(board, i - 1, j, word[1:]) or self.dfs(board, i + 1, j, word[1:]) or self.dfs(board, i, j - 1, word[1:]) or self.dfs(board, i, j + 1, word[1:])
        board[i][j] = tmp  # recover board[i][j]
        return ans
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0079-Word-Search/0079.py)