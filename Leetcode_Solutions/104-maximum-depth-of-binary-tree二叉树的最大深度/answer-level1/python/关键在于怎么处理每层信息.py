### 解题思路
1、依然是queue，来实现层次遍历；
2、依然是为了得到level，那么每次把一个level的都处理完；
3、queue中保存的是下一层的所有元素，每次记录size，只处理这一层的内容，剩余节点就是下一层了下次循环处理；

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections


class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        queue = collections.deque([root])
        level = 0
        while len(queue) > 0:
            level_size = len(queue)
            level += 1
            for _ in range(level_size):
                node = queue.popleft()
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
        return level


```