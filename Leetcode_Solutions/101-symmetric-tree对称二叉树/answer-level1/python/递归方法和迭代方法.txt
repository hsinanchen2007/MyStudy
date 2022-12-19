```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:

        if not root:
            return True

        def isSame(left, right):
            if left == None or right == None:
                if left == None and right == None:
                    return True
            elif left.val == right.val:
                return isSame(left.left, right.right) and isSame(left.right, right.left)
            else:
                return False
        
        return isSame(root.left, root.right)
```
递归方法

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        queue = [root.left, root.right]
        while len(queue) != 0:
            left = queue.pop(0)
            right = queue.pop(0)
            if not (left and right):
                if not (left or right):
                    continue
                else:
                    return False
            elif left.val == right.val:
                queue.append(left.left)
                queue.append(right.right)
                queue.append(left.right)
                queue.append(right.left)
            else:
                return False
        return True
```
迭代方法

事实证明，迭代方法速度远比递归方法快。
