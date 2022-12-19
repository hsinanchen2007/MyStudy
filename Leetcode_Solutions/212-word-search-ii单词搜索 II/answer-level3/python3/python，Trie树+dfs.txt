### 解题思路
此处撰写解题思路

### 代码

```python3
class TreeNode:
    def __init__(self):
        self.links = dict()
        self.isEnd = False
class Trie:
    def __init__(self):
        self.root = TreeNode()

    def insert(self, word):
        cur = self.root
        for char in word:
            if char not in cur.links:
                cur.links[char]=TreeNode()
            cur = cur.links[char]
        cur.isEnd = True


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        if not board or not words:
            return []
        tree = Trie()
        for word in words:
            tree.insert(word)
        
        res = set()
        
        def dfs(i,j, root, path):
            if i<0 or i>=len(board) or j<0 or j>=len(board[0]) or board[i][j] not in root.links:
                return
            char = board[i][j]
            path = path+[char]
            # 访问过的用-代替掉，等这个dfs完了再补回来
            board[i][j]='-'
            if root.links[char].isEnd:
                res.add(''.join(path))

            dfs(i+1,j, root.links[char], path)
            dfs(i-1,j, root.links[char], path)
            dfs(i,j-1, root.links[char], path)
            dfs(i,j+1, root.links[char], path)
            # 恢复原来的值
            board[i][j]=char
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                dfs(i,j, tree.root, [])
        return list(res)
        

                
        
        
```