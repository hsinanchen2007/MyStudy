使用level来辨别是那层，然后奇数层从左边pop（），从右边push（）。偶数层从右边pop（），从左边push（）。
```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        queue = collections.deque([root])
        res = []
        level = 0
        while queue:
            res.append([])
            length = len(queue)
            if level%2 == 0:
                while length > 0:
                    node = queue.popleft()
                    res[level].append(node.val)
                    if node.left: queue.append(node.left)
                    if node.right: queue.append(node.right)
                    length -= 1
            else:
                while length > 0:
                    node = queue.pop()
                    res[level].append(node.val)
                    if node.right: queue.appendleft(node.right)
                    if node.left: queue.appendleft(node.left)
                    length -= 1
            level += 1
        return res
```
