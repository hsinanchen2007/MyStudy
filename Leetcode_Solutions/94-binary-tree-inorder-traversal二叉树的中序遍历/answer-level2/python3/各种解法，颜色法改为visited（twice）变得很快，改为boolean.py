### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        # WHITE, GRAY = 0, 1
        res = []
        stack = [(False, root)]
        while stack:
            visited, node = stack.pop()
            if node is None: continue
            if not visited:
                stack.append((False, node.right))
                stack.append((True, node))
                stack.append((False, node.left))
            else:
                res.append(node.val)
        return res

# class Solution:
#     def inorderTraversal(self, root: TreeNode) -> List[int]:
#         res = []
#         if root is None:
#             return root
#         stack = []
#         node = root
#         while True:
#             while node:
#                 stack.append(node)
#                 node = node.left
#             if stack == []:
#                 break
#             node = stack.pop()
#             res.append(node.val)
#             node = node.right
#         return res

# class Solution:
#     def inorderTraversal(self, root: TreeNode) -> List[int]:
#         res = []
#         if root:
#             res += self.inorderTraversal(root.left)
#             res.append(root.val)
#             res += self.inorderTraversal(root.right)
#         return res
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# class Solution:
#     def inorderTraversal(self, root: TreeNode) -> List[int]:
        
#         res = []
#         stack = [root]

#         while stack:
#             node = stack.pop()
            
#             while node.left:
#                 stack.append(node.left)

#             res.append(stack.pop)
#             res.append(node)
            
#             while node.right:
#                 stack.append(node.left)





#     def inorderTraversal(self, root: TreeNode) -> List[int]:
#         res = []
#         res = self.inorderHelper(root, res)
#         return res

#     def inorderHelper(self, root: TreeNode, res: List):   
        
#         if root is None:
#             return 
#         else:
#             self.inorderHelper(root.left, res)
#             res.append(root.val)
#             self.inorderHelper(root.right, res)

#         return res

# class Solution:
#     def inorderTraversal(self, root: TreeNode) -> List[int]:
#         res = []
#         stack = []
#         # 用node当做指针
#         node = root
#         while node or stack:
#             # 把左子树压入栈中
#             while node:
#                 stack.append(node)
#                 node = node.left
#             # 输出 栈顶元素
#             node = stack.pop()
#             res.append(node.val)
#             # 看右子树
#             node = node.right
#         return res

```