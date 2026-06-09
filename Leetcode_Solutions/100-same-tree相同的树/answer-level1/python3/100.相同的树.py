### 解题思路
迭代判断
抑或:
1 xor 1 = 0
0 xor 0 = 0
1 xor 0 = 1

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
        #其中一个为None的话
        if p == None or q == None:
            #抑或判断两者是否同为None
            return not ((p == None) ^ ( q == None ))

        if p.val == q.val:
            return (self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right))
        else:
            return False
```
![image.png](https://pic.leetcode-cn.com/13e3fada9ab2bd09491d48e10e3f6f42250c95c02f4e5adb01da5b6ea5853ce5-image.png)
