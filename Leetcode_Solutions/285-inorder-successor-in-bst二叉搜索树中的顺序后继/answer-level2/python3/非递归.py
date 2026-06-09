```
class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        # 非递归
        DONE = 1
        UNDO = 0
        stack = [(root, UNDO)]
        got_it = False
        while stack:
            node, status = stack.pop()
            if not node:
                continue
            if status == UNDO:
                if p.val >= node.val:
                    stack.append((node.right, UNDO))
                stack.append((node, DONE))
                if p.val <= node.val:
                    stack.append((node.left, UNDO))
            elif status == DONE:
                if got_it:
                    return node
                if node == p:
                    got_it = True
        return None
```
