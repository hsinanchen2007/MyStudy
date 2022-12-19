### 解题思路
两棵树前序遍历保存下来，kmp比较

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        # write code here
        if not t:
            return False
        p1, p2 = self.preorder(s), self.preorder(t)
        return True if self.kmp(p1, p2) != -1 else False
    
    def preorder(self, root):
        stack = [root]
        res = []
        while stack:
            cur = stack.pop()
            if cur:
                res.append(cur.val)
                stack.append(cur.right)
                stack.append(cur.left)
            else:
                res.append('#')
        return res
    
    def kmp(self, txt, pat):
        if not pat:
            return 0
        m, n, nxt = len(txt), len(pat), self.getNext(pat)
        i, j = 0, 0
        while i < m and j < n:
            if j == -1 or txt[i] == pat[j]:
                i += 1
                j += 1
            else:
                j = nxt[j]
        return i-j if j == n else -1
    
    def getNext(self, s):
        nxt = [0 for _ in range(len(s))]
        nxt[0] = -1
        i, j = 0, -1
        while i < len(s)-1:
            if j == -1 or s[j] == s[i]:
                j += 1
                i += 1
                nxt[i] = j
            else:
                j = nxt[j]
        return nxt
```