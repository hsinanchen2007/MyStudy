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
    def isBalanced(self, root: TreeNode) -> bool:
        ans=0
        def depth(root):
            nonlocal ans
            if not root:
                return 0
            l=depth(root.left)
            r=depth(root.right)
            ans=max(ans,abs(l-r))
            return max(l,r)+1
        depth(root)
        return ans<=1

```