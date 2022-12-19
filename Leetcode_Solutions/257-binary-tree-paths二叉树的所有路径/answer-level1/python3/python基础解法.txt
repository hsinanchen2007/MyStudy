### 解题思路
1. 迭代，利用栈来迭代（宽度搜索优先）遍历树节点
2. 递归，利用递归来遍历树节点

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
        # if not root:
        #     return []
        
        # paths = []
        # stack = [(root, str(root.val))]
        # while stack:
        #     node, path = stack.pop()
        #     if not node.left and not node.right:
        #         paths.append(path)
        #     if node.left:
        #         stack.append((node.left, path + '->' + str(node.left.val)))
        #     if node.right:
        #         stack.append((node.right, path + '->' + str(node.right.val)))
        
        # return paths

        def construct_paths(root, path):
            if root:
                path += str(root.val)
                if not root.right and not root.left:
                    paths.append(path)
                else:
                    path += '->'
                    construct_paths(root.right, path)
                    construct_paths(root.left, path)
        paths = list()
        construct_paths(root, '')
        return paths

```