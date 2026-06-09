### 解题思路
深度优先遍历所有节点。
对每一个节点，如果是偶数节点，对它的四个孙子节点，存在的就将其加到全局变量Sum中。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    Sum = 0
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        self.solve(root)
        return self.Sum
    
    def solve(self, root:TreeNode):
        if root == None:
            return 
        elif root.val % 2 == 0:
            if root.left != None:
                if root.left.left != None:
                    self.Sum += root.left.left.val
                if root.left.right != None:
                    self.Sum += root.left.right.val
            if root.right != None:
                if root.right.left != None:
                    self.Sum += root.right.left.val
                if root.right.right != None:
                    self.Sum += root.right.right.val
        self.solve(root.left)
        self.solve(root.right)
        return 
```