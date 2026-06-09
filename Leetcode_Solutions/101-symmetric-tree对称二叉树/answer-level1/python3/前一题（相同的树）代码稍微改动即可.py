### 解题思路
思路借助了前一题相同的树[https://leetcode-cn.com/problems/same-tree/]()，利用递归函数判读左子树右字数是否对称。
相同的树那一题是p的左子树的值是否等于q的左子树的值，而本体应将条件改为p的左子树的值是否等于q的右子树的值

### 代码

```python3
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
        def issame(p,q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            if p.val != q.val:
                return False
            return issame(p.left,q.right) and issame(p.right,q.left)
        return issame(root.left,root.right)
```