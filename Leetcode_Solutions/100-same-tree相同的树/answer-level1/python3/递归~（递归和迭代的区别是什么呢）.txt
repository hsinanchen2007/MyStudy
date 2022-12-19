### 解题思路
看看这三个到底是啥~
1. p.val:
TreeNode{val: 1, left: TreeNode{val: 2, left: None, right: None}, right: TreeNode{val: 3, left: None, right: None}} 
2. p.left:
TreeNode{val: 2, left: None, right: None} 
3. p.right:
TreeNode{val: 3, left: None, right: None}

![image.png](https://pic.leetcode-cn.com/fd8b6678bbcc92b4e3118cb2e55f1234dfd425e125e6bcc4d5df3bd7384739a0-image.png)

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
        if not p and not q: return True
        if not p or not q: return False
        if p.val != q.val: return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```