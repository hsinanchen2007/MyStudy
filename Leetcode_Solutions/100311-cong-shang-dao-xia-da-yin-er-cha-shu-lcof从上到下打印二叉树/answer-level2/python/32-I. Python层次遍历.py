### 解题思路
对于树的层次遍历最常用的方法就是使用队列，每次将队首的节点的非空左右孩子入队，再删除队首节点，直到队空。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        queue = [root]
        res = []
        while len(queue):
            node = queue[0]
            res.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
            del queue[0]
        return res
```