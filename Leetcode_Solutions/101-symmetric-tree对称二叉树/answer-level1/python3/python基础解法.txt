### 解题思路
1. 递归，试用递归去判断值是否相等，判断left.left与right.right；left.right与right.left是否相等。递归的出口有三个：1. left和right都为空 2. left和right一边为空 3. left和right的值不相等
2. 使用队列保存值，然后去判断是否成立
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        # if not root:
        #     return True
        
        # def dfs(left, right):
        #     if not (left or right):
        #         return True
        #     if not (left and right):
        #         return False
        #     if left.val != right.val:
        #         return False
        #     return dfs(left.right, right.left) and dfs(left.left, right.right)
        # return dfs(root.left, root.right)

        if not root or not (root.left or root.right):
            return True
        queue = [root.left, root.right]
        while queue:
            left = queue.pop(0)
            right = queue.pop(0)
            if not (left or right):
                continue
            if not (left and right):
                return False
            if left.val != right.val:
                return False
            queue.append(left.left)
            queue.append(right.right)
            queue.append(left.right)
            queue.append(right.left)
        return True
            
```