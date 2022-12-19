### 解题思路
1 预处理
2 双栈+非递归DFS
栈1保存DFS记录，栈2记录匹配的字符路径，在这个字符路径上的字符之后是不能再进入栈1
mem记录在栈2里面的字符状态
关键点是在某个字符不匹配之后，栈2要进行弹出，确保栈2的top是当前字符的前一个字符，所以使用k记录匹配的深度

### 代码

```python
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not board:
            return False
        m, n = len(board), len(board[0])
        wn = len(word)
        if m * n <= wn:
            d = [0] * 128
            for s in word:
                d[ord(s)] += 1
            for i in board:
                for j in i:
                    d[ord(j)] -= 1
            for c in d:
                if c > 0:
                    return False

        mem = [ [0] * n for x in range(m)]
        for i in range(m):
            for j in range(n):
                k = 0
                if board[i][j] != word[k]:
                    continue
                stack = [(i, j, k)]
                stackpath = []
                while stack:
                    p, q, k = stack.pop()
                    while stackpath:
                        sp, sq, sk = stackpath[-1]
                        if sk == k:
                            break
                        else:
                            stackpath.pop()
                            mem[sp][sq] = 0
                    if board[p][q] == word[k]:
                        k += 1
                        if k == wn:
                            return True
                        mem[p][q] = 1
                        stackpath.append((p, q, k))
                        if p > 0 and not mem[p - 1][q]:
                            stack.append((p - 1, q, k))
                        if p < m - 1 and not mem[(p + 1)][q]:
                            stack.append((p + 1, q, k))
                        if q > 0 and not mem[p][(q - 1)]:
                            stack.append((p, q - 1, k))
                        if q < n - 1 and not mem[p][(q + 1)]:
                            stack.append((p, q + 1, k))
                while stackpath:
                    sp, sq, sk = stackpath.pop()
                    mem[sp][sq] = 0
        return False
```