### 解题思路
二叉搜索树中序遍历的结果是升序的

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root:
            res = list()

            def mid_visit(root):
                if root.left:
                    mid_visit(root.left)

                res.append(root.val)

                if root.right:
                    mid_visit(root.right)

            mid_visit(root)

            if len(res) == 1:
                return True
            else:
                for i in range(1, len(res)):
                    if res[i] <= res[i - 1]:
                        return False
                    
        return True
```