### 解题思路
最开始想着层次遍历，然后判断两个结果是否相等，然而一直报错，看了[@labuladong](/u/labuladong/)东哥的思路后如醍醐灌顶，思路简洁明了，代码也是清爽的不行。
· 首先若两个树全部为空，那自然是相等的，直接返回True即可；
· 其次若有一个非空，另一个为空，自然是不等的，直接返回False即可；
· 再者，若两棵树的根节点值不相等，那这两棵树自然也是不等的，直接返回False即可；
· 最后直接两次递归分别判断两棵树的左孩子是否相等，右孩子是否相等即可

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
        if not p and q:
            return False
        if p and not q:
            return False
        if p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```