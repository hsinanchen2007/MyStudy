```
from collections import deque
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:return 0
        q = deque()
        q.append(root)
        cnt = 1
        while q:
            length = len(q)
            for _ in range(length):
                node = q.popleft()
                if node.left is None and node.right is None:
                    return cnt
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            cnt += 1
```
和最大区别就是：最大深度要遍历完，最小深度的要判断当前层，存在一个节点 其没有左右子节点就可以返回了。