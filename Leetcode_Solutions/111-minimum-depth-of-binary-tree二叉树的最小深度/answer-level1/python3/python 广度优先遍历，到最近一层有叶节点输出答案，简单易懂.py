

class Solution:
```
代码块
```

    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        queue = []
        queue.append(root)
        res = 0
        while queue:
            queue_len = len(queue)
            res += 1
            for _ in range(queue_len):
                node = queue.pop(0)
                if self.is_leave(node):
                    return res
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return res
    

    def is_leave(self,node):
        if not node.left and not node.right:
            return True
        return False