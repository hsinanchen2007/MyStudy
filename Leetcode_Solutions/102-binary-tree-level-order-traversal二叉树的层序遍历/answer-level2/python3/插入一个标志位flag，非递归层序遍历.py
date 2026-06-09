```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return None
        res = []
        stack = []
        flag = TreeNode('cut')
        stack.append(root)
        stack.append(flag)
        level = []
        while stack:
            node = stack.pop(0)
            if node.val == 'cut':
                res.append(level)
                if not stack:
                    break
                level = []
                stack.append(node)
            else:
                level.append(node.val)
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
        return res
```
