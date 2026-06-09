### 解题思路
此题简单递归即可解决。

### 官方题解收获：

if not p and not q:
    pass
if not p or not q:   # p, q 中至少有一个 None， 而前面 p, q 都为 None 已经处理过了
    pass

官方题解还提供了一种层次遍历的写法。后续来掌握。


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
        if p == None and q == None:
            return True
        if (p == None and q) or (p and q==None):
            return False
            
        if p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        else:
            return False
```