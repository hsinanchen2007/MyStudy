### 解题思路

这道题主要考察递归思想，比较两棵树的节点。

有三种可能：

①两颗树完全相等，s.left,t.left和s.right,t.right同时进行递归 ②t和s的左子树进行比较，s.left,t进行递归 ③t和s的右子树进行比较，s.right,t进行递归

注意：这三个条件应该是相互独立的，采用or运算。

错误思想：不可把三个条件放在同一表达式中。

例如:

return (s.val == t.val and self.istree(s.left, t.left) and self.istree(s.right, t.right)) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

这种情况下，会破坏他们之间的独立性。导致结果错误！！！

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not s and not t:
            return True
        if not s or not t:
            return False
        return self.istree(s,t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def istree(self,s,t):
        if not s and not t:
            return True
        if not s or not t:
            return False
        return s.val == t.val and self.istree(s.left, t.left) and self.istree(s.right, t.right)
```