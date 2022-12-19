### 解题思路
1. 遍历所有节点，用set记录所有的值。
2. 判断set的长度是否为1。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.res = set()

    def isUnivalTree(self, root: TreeNode) -> bool:
        
        if not root:
            return True
        self.res.add(root.val)
        self.isUnivalTree(root.left)
        self.isUnivalTree(root.right)

        return len(self.res) == 1
        

```