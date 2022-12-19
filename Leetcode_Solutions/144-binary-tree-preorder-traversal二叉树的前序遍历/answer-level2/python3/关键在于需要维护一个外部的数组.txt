### 解题思路
在构造函数中维护一个数组，用于存储数据；

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.nodes = []

    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root:
            self.nodes.append(root.val)
            self.preorderTraversal(root.left)
            self.preorderTraversal(root.right)
        return self.nodes
```