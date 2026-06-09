Improvement of [(Python) DFS with stand-alone traversal on right boundary nodes](https://leetcode-cn.com/problems/boundary-of-binary-tree/solution/python-dfs-with-stand-alone-traversal-on-right-bou/). Clean one time DFS traversal, preorder for left nodes and postorder for right nodes.



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

        left_result = []
        right_result = []
        left_stack = []
        right_stack = []


        if root.left:
            left_boundary_traversal_done = False
            left_stack.append(root.left)

            while left_stack:
                node = left_stack.pop()
                left = node.left
                right = node.right

                if right:
                    left_stack.append(right)
                if left:
                    left_stack.append(left)

                if (not left and not right) or not left_boundary_traversal_done:
                    if not left and not right:
                        left_boundary_traversal_done = True
                    left_result.append(node.val)

        if root.right:
            right_boundary_traversal_done = False
            right_stack.append(root.right)

            while right_stack:
                node = right_stack.pop()
                left = node.left
                right = node.right

                if left:
                    right_stack.append(left)
                if right:
                    right_stack.append(right)

                if (not left and not right) or not right_boundary_traversal_done:
                    if not left and not right:
                        right_boundary_traversal_done = True
                    right_result.append(node.val)
        if not root.left and not root.right:
            return [root.val]

        right_result.reverse()

        return [root.val] + left_result + right_result
```

![Screen Shot 2020-01-12 at 17.44.55.png](https://pic.leetcode-cn.com/5d728f7793ed261026d8c92ce85842b2c05582ac789eedce22dcc1ecbbd44d9d-Screen%20Shot%202020-01-12%20at%2017.44.55.png)
