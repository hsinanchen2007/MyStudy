### 解题思路
不太喜欢DFS，因为DFS如果遇到1万个单链表式（例如只有左节点，10000层）的话，会暴栈..
用BFS写

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from copy import copy

class Solution(object):
    def BSTSequences(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return [[]]
        queue = [[[root], []]]
        last_queue = []
        while queue:
            new_queue = []
            for nodes, v in queue:
                for i, node in enumerate(nodes):
                    new_v = copy(v) + [node.val]
                    new_nodes = nodes[0:i] + nodes[i+1:]
                    if node.left:
                        new_nodes.append(node.left)
                    if node.right:
                        new_nodes.append(node.right)
                    new_queue.append([new_nodes, new_v])
            last_queue = queue
            queue = new_queue
        return [v for nodes, v in last_queue]


```