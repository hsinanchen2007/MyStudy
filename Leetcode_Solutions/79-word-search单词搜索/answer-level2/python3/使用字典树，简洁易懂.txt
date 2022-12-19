```
class Solution:
    def exist(self, board, word: str) -> bool:
        trie = {}
        node = trie
        for c in word:
            node = node.setdefault(c, {})
        node['#'] = '#'

        def search(node, i, j, visited):
            if '#' in node:
                return True
            for ii, jj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                _i, _j = i + ii, j + jj
                if 0 <= _i < row and 0 <= _j < col and board[_i][_j] in node and (_i, _j) not in visited:
                    res = search(node[board[_i][_j]], _i, _j, visited | {(_i, _j)})
                    if res:
                        return res

        row, col = len(board), len(board) and len(board[0])
        for i in range(row):
            for j in range(col):
                if board[i][j] in trie:
                    if search(trie[board[i][j]], i, j, {(i, j)}):
                        return True
        return False
```
