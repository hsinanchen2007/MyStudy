### 解题思路
用栈对树进行层次遍历是很常用的方法，这道题只需要我们在向栈中存储节点的时候，不仅要存储节点的引用，还要存储节点的层数。

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
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        queue = [(root, 0)]
        cur_level = 0
        res = [[]]
        while len(queue):
            node, level = queue[0]
            if level == cur_level:
                res[-1].append(node.val)
            else:
                res.append([node.val])
                cur_level += 1
            if node.left:
                queue.append((node.left, level + 1))
            if node.right:
                queue.append((node.right, level + 1))
            del queue[0]
        return res
```