除了存储每个node，还存储了root到这个node的sum，如果该node是叶子节点，则和target进行比较, 相等返回True。若所有叶子的sum和target都不相等，返回False。
```
class Solution:
    def hasPathSum(self, root: TreeNode, target: int) -> bool:
        if not root: return False
        stack = [(root.val, root)]
        while stack:
            sum_, node = stack.pop()
            if node.right:
                stack.append((sum_ + node.right.val, node.right))
            if node.left:
                stack.append((sum_ + node.left.val, node.left))
            if not node.left and not node.right and sum_ == target:
                return True
        return False
```

递归
```
class Solution:
    def hasPathSum(self, root: TreeNode, target: int) -> bool:
        if not root: return False
        if not root.left and not root.right: return root.val == target
        return self.hasPathSum(root.left, target - root.val) or self.hasPathSum(root.right, target - root.val)
```
