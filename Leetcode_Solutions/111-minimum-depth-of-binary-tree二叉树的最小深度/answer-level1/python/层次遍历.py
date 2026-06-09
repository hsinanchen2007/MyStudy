### 解题思路
求树的高度时可用层次遍历，这里稍微改一下，遇到叶子节点就直接返回。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        queue = []
        pre = root
        queue.append(root)
        depth = 0
        while queue:
            q = queue[0]
            del queue[0]
            if q.left:
                queue.append(q.left)
            if q.right:
                queue.append(q.right)
            if not q.left and not q.right:  # 发现叶节点吗，直接返回
                return depth + 1
            if q == pre:
                depth += 1
                if queue:#这里需要判断队列是否为空，否则会报错
                    pre = queue[-1]
        return depth+1
```