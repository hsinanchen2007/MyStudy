### 解题思路
遍历

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def get_depth(root):
            if not root:
                return 0
            else:
                return 1+max(get_depth(root.left),get_depth(root.right))
        
        def check(root):
            if not root:
                return True
            else:
                if abs(get_depth(root.left)-get_depth(root.right))>1:
                    return False
                else:
                    return check(root.left) and check(root.right)
        return check(root)
```