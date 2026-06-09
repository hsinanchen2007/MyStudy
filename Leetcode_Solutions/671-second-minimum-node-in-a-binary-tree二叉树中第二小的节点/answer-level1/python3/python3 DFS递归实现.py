### 解题思路
根据题意，只需要找到左子树和右子树中比根节点的值大的值即可，一旦找到就立即返回该值。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        return self.helper(root,root.val)

    def helper(self,root,value):
        if not root:
            return -1
        if root.val>value:
            return root.val
        l=self.helper(root.left,value)
        r=self.helper(root.right,value)
        if l==-1:
            return r
        if r==-1:
            return l
        return min(r,l)

```