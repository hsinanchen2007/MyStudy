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
        stackLeft = list() # 使用层序遍历，然后左边的是从左节点开始
        stackRight = list() # 使用层序遍历，然后右边的是从右节点开始
        
        stackLeft.append(root.left)
        stackRight.append(root.right)
        
        while stackLeft or stackRight:
            left = stackLeft.pop(0)
            right = stackRight.pop(0)
            if left and right:
                if left.val == right.val:
                    stackLeft.append(left.left)
                    stackLeft.append(left.right)
                    stackRight.append(right.right)
                    stackRight.append(right.left)
                else:
                    return False
            else:
                if left or right:
                    return False
            
        return True
```
