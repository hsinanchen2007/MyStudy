### 解题思路
还是要讲清楚里面diameter是点中的线有多少，所以
max(left_height+right_height, diameter(r.right),diameter(r.left))
height function也是计算，点间的线有多少

```
def _height(node: TreeNode) -> int:
    if not node:
        return 0
    left = _height(node.left)
    right = _height(node.right)
    return max(left,right) + 1
```
l_h = _height(root.left)
r_h = _height(root.right)
注意这里没有加一，是因为diameter是node中的线有多少
return max(l_h + r_h, self.diameterOfBinaryTree(root.left), self.diameterOfBinaryTree(root.right))


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        def _height(node: TreeNode) -> int:
            if not node:
                return 0
            left = _height(node.left)
            right = _height(node.right)
            return max(left,right) + 1
        
        if not root:
            return 0

        l_h = _height(root.left)
        r_h = _height(root.right)

        return max(l_h + r_h, self.diameterOfBinaryTree(root.left), self.diameterOfBinaryTree(root.right))

# class Solution(object):
#     def diameterOfBinaryTree(self, root):
#         self.ans = 1
#         def depth(node):
#             if not node: return 0
#             L = depth(node.left)
#             R = depth(node.right)
#             self.ans = max(self.ans, L+R+1)
#             return max(L, R) + 1

#         depth(root)
#         return self.ans - 1

```