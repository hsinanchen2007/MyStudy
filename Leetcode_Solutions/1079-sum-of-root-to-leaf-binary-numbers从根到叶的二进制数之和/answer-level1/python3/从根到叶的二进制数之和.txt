### 解题思路
我的思路：累加的递归可以参考这个，有思路但是递归还不怎么会写，这个是受其它题解的启发
        
复杂度分析：                                                             
        • 时间复杂度：o(n)
        • 空间复杂度：o(1)
### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        result = 0
        s = 0
        def helper(root,s):
            if not root:
                return None
            s = s*2 + root.val
            if not root.left and not root.right:
                nonlocal result
                result += s
            else:
                helper(root.left,s)
                helper(root.right,s)
        helper(root,s)
        return result
            
```