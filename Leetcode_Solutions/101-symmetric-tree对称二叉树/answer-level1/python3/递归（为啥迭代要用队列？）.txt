### 解题思路
跟第100题代码基本都一样……
还是不会迭代……emmm，为啥迭代要用队列呀？不觉得很麻烦吗？？

![image.png](https://pic.leetcode-cn.com/c393c5f9e3fad42c4f2834135f632eedd64ff23c7f7dc401c2ef16f4a2af0c4e-image.png)

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
        return self.temp(root, root)
    def temp(self, l, r):
        if not l and not r: return True
        if not l or not r: return False
        if l.val != r.val: return False
        return self.temp(l.left, r.right) and self.temp(l.right, r.left) 

```