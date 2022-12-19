### 解题思路
就是一个dfs
话说谁教教我bfs咋掌握 dfs感觉稍微入门了
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def inOrder(root):
            if not root :
                return []
            res=inOrder(root.left)+[root.val]+inOrder(root.right)
            return res
        return sorted(inOrder(root1)+inOrder(root2))
```