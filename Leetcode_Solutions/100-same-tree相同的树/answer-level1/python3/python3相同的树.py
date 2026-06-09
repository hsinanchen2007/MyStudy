### 解题思路
递归调用函数判断目标树的左子树和右子树是否一样。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        elif not p or not q:
            return False
        if p.val==q.val:
            ans=(self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right))
        else:
            ans=False
        return ans

```

![image.png](https://pic.leetcode-cn.com/ff818c232ddb22669343439f1c98e9605f047b2a2750d4e754e2ae20952ff39a-image.png)
