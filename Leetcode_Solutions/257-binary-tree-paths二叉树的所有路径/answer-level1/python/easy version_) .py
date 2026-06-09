### 解题思路

If we approach to the leave node, just put the path into the list, and we would use recursion to look through 
the tree, make sure all possibilities would be considered ! 

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        def cal(root,path):
            if root:
                path += str(root.val)
                if not root.left and not root.right:
                    result.append(path)
                else:
                    path += '->'
                    cal(root.left,path)
                    cal(root.right,path)
        result = []
        cal(root, "")
        return result
```