### 解题思路
如果按照正常的方法去写递归的话，只有一个节点，判断的时候就变成了当前该节点的左右是否相等
分享大神讲解：https://www.bilibili.com/video/av77275498?from=search&seid=17634446045305830625

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
        def isSym(left, right):
            if left and right:
                return left.val==right.val and isSym(left.left, right.right) and isSym(left.right, right.left)
            else:
                return left == right
        
        return isSym(root, root)
```