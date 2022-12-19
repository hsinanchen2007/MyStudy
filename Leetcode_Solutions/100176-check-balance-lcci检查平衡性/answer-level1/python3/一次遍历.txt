### 解题思路
用ans记录左右子树的最大深度差，
depth函数求取以某节点为根节点的树的最大深度

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        ans=0
        def depth(root):
            nonlocal ans
            if not root:  return 0
            left=depth(root.left)
            right=depth(root.right)
            ans=max(ans,abs(left-right))
            return max(left,right)+1
        depth(root)
        return ans<=1
```