### 解题思路
如果root为空，直接返回0

定义method函数来返回节点的最小深度
如果root为叶节点，返回1
递归调用method函数，返回左孩子的最小深度和右孩子的最小深度的最小值加1，即
```
temp = []
if N.left:
    temp.append(method(N.left))
if N.right:
    temp.append(method(N.right))
return min(temp)+1
```


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        def method(N):
            if N.left is None and N.right is None:
                return 1
            temp = []
            if N.left:
                temp.append(method(N.left))
            if N.right:
                temp.append(method(N.right))
            return min(temp)+1
        return method(root)
```