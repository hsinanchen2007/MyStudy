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
    def __init__(self):
        self.deep_now = 0
        self.rightside = []
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        self.search_right(root,1)
        self.search_right(root.left, 2)
        return self.rightside
    def search_right(self, root, depth):
        if not root:
            return 
        if depth>self.deep_now:
            self.deep_now=depth
            self.rightside.append(root.val)
        self.search_right(root.right, depth+1)
        self.search_right(root.left, depth+1)
```