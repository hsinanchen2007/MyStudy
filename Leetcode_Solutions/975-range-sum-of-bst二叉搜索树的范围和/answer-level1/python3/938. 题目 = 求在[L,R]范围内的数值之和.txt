### 解题思路
1. 如果当前节点值在[L,R]之间，将数值加到结果中去。
2. L如果小于当前节点值，搜索左子树符合条件的值。
3. R如果大于当前节点值，搜索右子树符合条件的值。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        if not root:
            return 0
        res = 0
        if L <= root.val <= R:
            res += root.val
        if L <= root.val:
            res += self.rangeSumBST(root.left, L, R)
        if R >= root.val:
            res += self.rangeSumBST(root.right, L, R)
        
        return res
```