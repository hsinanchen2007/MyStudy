### 解题思路
我的思路：递归写法
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)

### 代码

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1 and not t2:
            return None
        elif t1 and not t2:
            return t1
        elif not t1 and t2:
            return t2
        else:
            val_1 = t1.val
            val_2 = t2.val
            t1.val = val_1 + val_2
            t1.left = self.mergeTrees(t1.left,t2.left)
            t1.right = self.mergeTrees(t1.right,t2.right)
            return t1
```