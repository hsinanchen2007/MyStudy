### 解题思路
部分递归

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        self.ans=0
        def res(root,L,R):
            if root:
                if root.val>L and root.left:
                    res(root.left,L,R)
                if L<=root.val<=R:
                    self.ans+=root.val
                if  root.val<R and root.right:
                    res(root.right,L,R)
        res(root,L,R)
        return self.ans
```