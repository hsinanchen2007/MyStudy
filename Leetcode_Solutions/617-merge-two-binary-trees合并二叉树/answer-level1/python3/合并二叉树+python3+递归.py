### 递归
执行用时 :100 ms, 在所有Python3提交中击败了98.86%的用户；内存消耗 :13.4 MB, 在所有Python3提交中击败了99.19%的用户

思路：如果当前两个树都为非空，则值相加，若有一个为空，则返回另外一个。代码如下：

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1 and t2:
            return t2               
        elif t1 and t2:
            t1.val = t2.val+t1.val
            t1.left = self.mergeTrees(t1.left,t2.left)
            t1.right = self.mergeTrees(t1.right,t2.right)
        return t1
        
```