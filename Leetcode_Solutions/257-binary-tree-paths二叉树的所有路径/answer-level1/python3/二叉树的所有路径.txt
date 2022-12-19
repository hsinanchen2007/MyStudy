### 解题思路
递归方法.

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
        if not root:
            return None
        result = []
        s = ''
        def helper(root,s):
            if not root:
                return None
            s += str(root.val)
            if not root.left and not root.right:
                result.append(s)
            else:
                s += '->'
                helper(root.left,s)
                helper(root.right,s)
            # if root.left:
            #     s += '->'
            #     helper(root.left,s)
            # elif root.right:
            #     s += '->'
            #     helper(root.right,s)
            # else:
            #     result.append(s)
        helper(root,s)
        return result

```