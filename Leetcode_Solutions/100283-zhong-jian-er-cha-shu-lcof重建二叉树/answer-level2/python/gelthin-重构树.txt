### 解题思路
参见题解 [主站 105 题](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def helper(left, right):
            if left>right:
                return None
            
            nonlocal pre_idx
            root = TreeNode(preorder[pre_idx])
            pre_idx += 1
            index = inorder.index(root.val)
            root.left = helper(left, index-1)
            root.right = helper(index+1, right)

            return root
        pre_idx = 0
        return helper(0, len(preorder)-1)

```