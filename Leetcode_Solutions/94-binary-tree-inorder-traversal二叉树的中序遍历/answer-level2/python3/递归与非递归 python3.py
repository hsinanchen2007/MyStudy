### 解题思路
递归与非递归 python3

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 递归
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        res = []
        self.inorder(root,res)
        return res

    def inorder(self,root,res):
        if root:
            self.inorder(root.left,res)
            res.append(root.val)
            self.inorder(root.right,res)

# 非递归
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        res = []
        stack = []
        curr = root
        while(stack or curr):
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop(-1)
            res.append(curr.val)
            curr = curr.right
        return res
        
```