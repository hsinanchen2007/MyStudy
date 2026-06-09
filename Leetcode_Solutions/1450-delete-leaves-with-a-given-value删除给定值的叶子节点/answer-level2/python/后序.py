### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if not root:
            return None
        def helper(root):
            if not root:
                return True

            j1 = helper(root.left)
            j2 = helper(root.right)
            
            if j1:
                root.left = None
            if j2:
                root.right = None
            if j1 and j2 and root.val == target:
                root = None
                return True
            else:
                return False

        j = helper(root)
        if root.val == target and j:
            return None
        return root


            


            

                
```