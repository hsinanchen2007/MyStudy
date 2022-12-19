Python3 , 方法一：根据每个word搜索一遍整个board；方法二：先把所有word存入字典树，然后搜索board（下附代码）
```
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

END_WORD = '#'

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        if not board or not board[0] or not words:   return []
        
        self.rows, self.cols = len(board), len(board[0])
        self.result = set()
        
        root = {}
        for word in words:
            node = root
            for char in word:
                node = node.setdefault(char, {})
            node[END_WORD] = END_WORD
            
         
        for row in range(self.rows):
            for col in range(self.cols):
                if board[row][col] in root:
                    self._dfs(board, row, col, root, '')
        return list(self.result)
    
    
    def _dfs(self, board, row, col, cur_node, cur_word):
        cur_word += board[row][col]
        cur_node = cur_node[board[row][col]]
        
        if END_WORD in cur_node:
            self.result.add(cur_word)
            
        temp, board[row][col] = board[row][col], '@'  
        for move in range(4):
            cur_row = row + dy[move]
            cur_col = col + dx[move]
                                          
            if 0<=cur_row<self.rows and 0<=cur_col<self.cols and board[cur_row][cur_col] != '@' and board[cur_row][cur_col] in cur_node:
                self._dfs(board, cur_row, cur_col, cur_node, cur_word)
        board[row][col] = temp
```
