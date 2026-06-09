```python
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # build a trie tree: O(N * M)
        # dfs traverse the board
        if board == [] or board == [[]]: return []
        trie = {}
        res_set = set()
        row, col = len(board), len(board[0])

        def generate_trie_tree(trie, words):
            for word in words:
                dic = trie
                for w in word:
                    if w not in dic: dic[w] = {}
                    dic = dic[w]
                dic['#']  = '#'

        def start_with(trie, word):
            dic = trie
            for w in word:
                if w not in dic: return (False, False)
                dic = dic[w]
            if '#' in dic: return (True, True)
            else: return (True, False)

        def traverse(i, j, board, visited, res_set, tempStr):
            tempStr += board[i][j]
            start, finish = start_with(trie, tempStr)
            if start:
                if finish: res_set.add(tempStr)
                visited[i][j] = True 
                for x, y in [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]:
                    if 0 <= x < row and 0 <= y < col and not visited[x][y]:
                        traverse(x, y, board, visited, res_set, tempStr)
                visited[i][j] = False

        generate_trie_tree(trie, words)
        visited = [[False] * col for _ in range(row)]
        for i in range(row):
            for j in range(col):
                traverse(i, j, board, visited, res_set, '')
        return list(res_set)
```