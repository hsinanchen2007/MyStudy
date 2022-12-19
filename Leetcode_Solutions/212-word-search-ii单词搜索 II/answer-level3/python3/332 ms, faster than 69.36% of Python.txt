### 解题思路
参考了这个大佬的代码
https://leetcode-cn.com/problems/word-search-ii/solution/pythonzi-dian-shu-dfs-by-mai-mai-mai-mai-zi/

核心是对words建立tire树! 然后对board进行dfs搜索, 直到遇见满足条件的字符串('#'标记代表isEnd)
而不是对board去建立tire树,
下面的代码也很简洁, 写的很好值得学习

### 代码

```python3
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        tire = {}
        for word in words: # 对words建立tire树, 
            node = tire
            for w in word:
                node = node.setdefault(w, {})
            node['#'] = True
        
        def search(i, j, node, pre, visited): # pre是当前字符串, visited标记i,j是否访问
            if '#' in node:
                res.add(pre) # 对于不变的board, res, h, w就不需要作为函数参数传递了!
            direc = [(-1, 0), (1, 0), (0, 1), (0, -1)]
            for d in direc:
                i_, j_ = i+d[0], j+d[1]
                if -1<i_<h and -1<j_<w and board[i_][j_] in node and (i_, j_) not in visited:
                    search(i_, j_, node[board[i_][j_]], pre+board[i_][j_], visited | {(i_,j_)})# visited.add((i_,j_))) 这样写不行, 因为add返回为None而不是visited本身


        h, w, res = len(board), len(board[0]), set() # res用set更快, 因为循环中间只是判断if in
        for i in range(h):
            for j in range(w):
                if board[i][j] in tire:
                    search(i, j, tire[board[i][j]], board[i][j], {(i,j)})
        return list(res)
```