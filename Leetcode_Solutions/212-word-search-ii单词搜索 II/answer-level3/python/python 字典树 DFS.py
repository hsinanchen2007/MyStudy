这道题整体思路是 1. 构建words的字典树 trie  2. 在board上深度优先遍历
但具体实现上，很多坑，在这里总结一下
1. trie 中 在board上找到的单词结尾要设成已访问，保证结果无重复
2. 在递归进入board下一个节点的前，要把当前节点设成已访问，不然未来可能重复访问该节点
3. 基于当前节点的深度优先搜索结束后，恢复board当前节点的值，便于之后单词的搜索

```python
class Node:
    def __init__(self):
        self.dict = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = Node()
        
    def insert(self, word):
        cur_node = self.root
        for alpha in word:
            if alpha not in cur_node.dict:
                cur_node.dict[alpha] = Node()
            cur_node = cur_node.dict[alpha]
        cur_node.is_end = True
        

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.h = len(board)
        self.w = len(board[0])
        self.res = []
        trie = Trie()
        for word in words:
            trie.insert(word) 
        for i in range(len(board)):
            for j in range(len(board[0])):
                cur_node = trie.root
                self.dfs(i, j, cur_node, board, "")
        return self.res
    
    def dfs(self, i, j, cur_node, board, word=""):
        char = board[i][j]
        if char in cur_node.dict: 
            word = word + char
            if cur_node.dict[char].is_end: 
                self.res.append(word)
                cur_node.dict[char].is_end = False # 保证无重复
            
            cur_node = cur_node.dict[char]
             
            board[i][j] = None # 关键！每个单词，不走回头路
            
            if i+1 < self.h and board[i+1][j]!=None:
                self.dfs(i+1, j, cur_node, board, word)
            if i > 0 and board[i-1][j]!=None:
                self.dfs(i-1, j, cur_node, board, word)
            if j+1 < self.w and board[i][j+1]!=None:
                self.dfs(i, j+1, cur_node, board, word)
            if j > 0 and board[i][j-1]!=None:
                self.dfs(i, j-1, cur_node, board, word)
                
            board[i][j] = char # 关键！在内存中恢复board
```

