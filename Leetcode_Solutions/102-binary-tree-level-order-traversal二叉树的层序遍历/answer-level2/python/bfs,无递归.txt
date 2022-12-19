### 解题思路
bfs
利用队列，先入先出
level与节点组合成一个元组， 同时写入,否则level的跟踪不好理解

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
        result = []
        level = 0
        queue = [(level, root)]

        while queue:
            level, node = queue[0]
            queue = queue[1:]

            if node != None:
                if len(result) == level: result.append([])

                result[level].append(node.val)
                queue.append((level+1, node.left))
                queue.append((level+1, node.right))

        return result

```