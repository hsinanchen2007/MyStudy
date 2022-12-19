### 解题思路
思路就是找到左右两颗子树中最小的值，并且这个值应该大于根节点

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
        def find(root,val):
            if not root:
                return float("inf")
            if root.val>val:
                return root.val
            left=find(root.left,val)
            right=find(root.right,val)
            return min(left,right)
        res=find(root,root.val) 
        return res if res!=float("inf") else -1
    
```