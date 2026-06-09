```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root is None:
            return False
        else:
            queue = [(root, root.val)]
            while queue:
                temp, tempSum = queue.pop(0)
                if tempSum == sum and not (temp.left or temp.right):
                    return True
                if temp.left:
                    queue.append((temp.left, temp.left.val + tempSum))
                if temp.right:
                    queue.append((temp.right, temp.right.val + tempSum))
            return False
```
