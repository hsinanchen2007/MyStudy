Not exactly optimized as you can probably figure out if a node is on right boundary during the first traversal.

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def boundaryOfBinaryTree(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        result = []
        stack = []
        stack.append(root)

        if root.left:
            left_boundary_traversal_done = False
        elif root.right:
            left_boundary_traversal_done = True
            result.append(root.val)
        else:
            return [root.val]


        while stack:
            node = stack.pop()
            left = node.left
            right = node.right

            if right:
                stack.append(right)
            if left:
                stack.append(left)

            if (not left and not right) or not left_boundary_traversal_done:
                if not left and not right:
                    left_boundary_traversal_done = True # No longer registering non-latest node as the left boundary is traversed.
                result.append(node.val)

        # Register nodes on right boundary.
        right_boundry = []
        root = root.right
        while root:
            if (root.left and root.right) or (not root.left and root.right):
                right_boundry.append(root.val)
                root = root.right
            elif root.left:
                right_boundry.append(root.val)
                root = root.left
            else:
                break
        right_boundry.reverse()

        return result + right_boundry


```
![Screen Shot 2020-01-10 at 16.42.56.png](https://pic.leetcode-cn.com/43ea8a7b61af283139fa74feead3b3a7949bb4fac7f1a215d10e0b38d2202be8-Screen%20Shot%202020-01-10%20at%2016.42.56.png)
