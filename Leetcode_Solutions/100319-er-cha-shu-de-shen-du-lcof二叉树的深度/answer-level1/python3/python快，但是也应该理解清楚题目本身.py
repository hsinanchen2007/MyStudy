### 解题思路
先用python捋一遍思想，后面再回过头来用C撸，这道题的难点就在于root的理解上吧。看了别人的才知道root是根节点的意思。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        return 0 if(root == None) else (max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1)
```