### 解题思路
递归生成左右子树

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generate(self, l, r):
        if l > r:
            return [None]
        elif l == r:
            return [TreeNode(l)]
        
        res = []
        for i in range(l, r+1):
            for left in self.generate(l, i-1):
                for right in self.generate(i+1, r):
                    root = TreeNode(i)
                    root.left, root.right = left, right
                    res.append(root)
        return res
    
    def generateTrees(self, n: int) -> List[TreeNode]:
        if not n:
            return []
        return self.generate(1, n)
            
```