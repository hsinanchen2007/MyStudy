### 解题思路
朴素思路,遍历其中一种一棵树,将所有的阶段存储在全局变量里面
遍历另一颗树,继续添加到变量里面
排序

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
        self.left = []
        self.right = []
        self.ans=[]
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        self.inorderTraversal(root1)
        self.inorderTraversal(root2)
        return sorted(self.ans)
  
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root:       
            self.inorderTraversal(root.left)
            self.ans.append(root.val)
            self.inorderTraversal(root.right)
        return self.ans
```