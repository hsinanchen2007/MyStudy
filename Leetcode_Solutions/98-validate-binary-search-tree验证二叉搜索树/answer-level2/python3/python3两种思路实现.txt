### 解题思路
按定义递归判断
中序遍历是递增数列

### 递归判断

```

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:

        def helper(root,lower = float('-inf'), upper = float('inf')):

            if not root:
                return True
            if root.val>=upper or root.val<=lower:
                return False

            return helper(root.left,lower,root.val) and helper(root.right,root.val,upper)

        return helper(root)
        
```

### 中序遍历

```

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack = []
        if not root:
            return True
        p = root
        pre = float('-inf')
        while(p or stack):
            if p:
                stack.append(p)
                p = p.left
            else:
                p = stack.pop()
                if p.val<=pre:
                    return False
                pre = p.val
                p = p.right
        return True
        
        
```