### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthLargest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        if k ==0:
            return 0
        resp = []
        def zhongxu(node):
            if node:
                zhongxu(node.left)
                resp.append(node.val)
                zhongxu(node.right)

        zhongxu(root)
        if resp :
            return resp[-k]
        return 0
```