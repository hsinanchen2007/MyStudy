![f69f08b2bc6c302125135864d7dc6da.png](https://pic.leetcode-cn.com/004ba45bc660a4480fd238df22f6e09986693e6b983f16fb9b0a778fd7d3675c-f69f08b2bc6c302125135864d7dc6da.png)
```
1 把words中的word存入前缀树
2 对board进行深度优先搜索
dfs三个核心部分：
1 新的字符不在搜索范围内，退出
2 新的字符在搜索范围内，且该字符与之前的字符串为words中的一个word,加入结果集，并将word结束标志置0，放置重复搜索
3 按深度优先递归搜索

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(i, j, t, s):
            ch = board[i][j]
            if ch not in t:
                return
            t = t[ch]
            if "end" in t and t["end"] == 1:
                res.append(s+ch)
                t["end"] = 0
            board[i][j] = "#"
            if i + 1 < m and board[i+1][j] != "#":
                dfs(i+1, j, t, s+ch)
            if i - 1 >= 0 and board[i-1][j] != "#":
                dfs(i-1, j, t, s+ch)
            if j + 1 < n and board[i][j+1] != "#":
                dfs(i, j+1, t, s+ch)
            if j - 1 >= 0 and board[i][j-1] != "#":
                dfs(i, j-1, t, s+ch)
            board[i][j] = ch
        
        # 将word存入前缀树    
        trie = {}
        for word in words:
            t = trie
            for ch in word:
                if ch not in t:
                    t[ch] = {}
                t = t[ch]
            t["end"] = 1
        
        m = len(board)
        n = len(board[0])
        res = []
        # 对board进行深度优先搜索
        for i in range(m):
            for j in range(n):
                dfs(i, j, trie, "")
        return res
```
