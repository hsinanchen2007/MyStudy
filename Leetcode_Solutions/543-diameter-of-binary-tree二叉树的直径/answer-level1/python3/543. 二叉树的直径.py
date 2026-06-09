### 解题思路
本题之前未遇到过，其实是广度遍历，但是不仅仅需要计算深度，还要计算左右子树共同的深度max(L+R,self.ans)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:

        
        self.ans = 0
        if not root:
            return 0
        self.depth(root)
        return self.ans
    def depth(self, p):
        L = 0
        R = 0
        if p.left:
            L = self.depth(p.left)    
        if p.right:
            R = self.depth(p.right)
        self.ans = max(self.ans, L+R) 
        return max(R,L) + 1        
```