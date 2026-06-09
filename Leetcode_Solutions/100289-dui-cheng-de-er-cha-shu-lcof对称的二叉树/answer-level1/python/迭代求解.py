### 解题思路
此处撰写解题思路

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
        if not root:
            return True
        queue=[]
        queue.append((root.left,root.right)) #当根节点非空，直接开始判断根节点的左右节点是否相等
        while queue:
            v1,v2 = queue.pop()
            if not v1 and not v2:
                continue
            if not v1 or not v2:
                return False
            if v1.val != v2.val:
                return False
            queue.append((v1.left,v2.right))
            queue.append((v1.right,v2.left))
        
        return True
```