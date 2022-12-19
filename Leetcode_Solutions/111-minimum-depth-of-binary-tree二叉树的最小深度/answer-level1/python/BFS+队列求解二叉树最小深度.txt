```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        else:
            queue = [(1, root)]
            ret = -1
            while queue:
                length = len(queue)
                for i in range(length):
                    depth, temp = queue.pop(0)
                    if temp:
                        if temp.left:
                            queue.append((depth + 1, temp.left))
                        if temp.right:
                            queue.append((depth + 1, temp.right))
                        if not (temp.left or temp.right):
                            if depth < ret or ret < 0:
                                ret = depth
            return ret
```
bfs+队列
