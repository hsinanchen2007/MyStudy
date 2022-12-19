题解一（递归）:
```
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return self.isMirror(root.left,root.right)

    def isMirror(self,p,q):
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        #if left.val != right.val:
        #    return False
        l=self.isMirror(p.left,q.right)
        r=self.isMirror(q.left,p.right)
        return p.val==q.val and l and r
```
题解二（迭代）：
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        from collections import deque
        def helper(p,q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            if p.val != q.val:
                return False
            return True
        deq=deque([(root,root),])
        while deq:
            p,q=deq.popleft()
            if not helper(p,q):
                return False
            if p:  # 当p和q为None时，此时p.left不成立，所以需要判断。
                deq.append((p.left,q.right))
                deq.append((p.right,q.left))
        return True
```