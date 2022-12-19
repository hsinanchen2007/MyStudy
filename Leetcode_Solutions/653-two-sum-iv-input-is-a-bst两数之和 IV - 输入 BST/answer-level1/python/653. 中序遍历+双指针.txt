### 解题思路
中序遍历是个难点。。。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:

        def inorder(root):
            if not root:
                return []
            # print(inorder(root.left) + [root.val] + inorder(root.right))
            return inorder(root.left) + [root.val] + inorder(root.right)
        
        target = inorder(root)
        
        left = 0
        right = len(target) - 1
        
        while left < right:
            if target[left] + target[right] == k:
                return True
            elif target[left] + target[right] > k:
                right -= 1
            elif target[left] + target[right] < k:
                left += 1
        
        return False
```