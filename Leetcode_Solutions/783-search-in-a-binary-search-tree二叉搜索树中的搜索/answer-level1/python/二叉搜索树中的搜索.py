### 解题思路
思路挺简单，就是递归：
树不存在时返回None；当当前节点的值等于给定值时，直接返回当前节点即可代表当前节点所在的子树；
若当前节点的值大于给定值，就去左子树中找；
若当前节点的值小于给定值，就去右子树中找。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return None
        if root.val == val:
            return root
        elif root.val > val:
            return self.searchBST(root.left, val)
        elif root.val < val:
            return self.searchBST(root.right, val)
        
        
```