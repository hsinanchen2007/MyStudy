### 解题思路
按照一定规律，拆分二叉树字符串。

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
        if len(preorder) == 0:
            return None
        m,ri,li,rp,lp = self.separate(preorder, inorder)
        root = TreeNode(m)
        # 处理当前节点
        if len(lp) > 0 or len(li) > 0 or len(rp) > 0 or len(ri) > 0:
            root.left = self.buildTree(lp, li)
            root.right = self.buildTree(rp, ri)
        return root

    def separate(self, preorder, inorder):
        middle = preorder[0]
        in_middle_index = inorder.index(middle)
        left_in = inorder[:in_middle_index]
        right_in = inorder[in_middle_index+1:]
        left_pre = preorder[1:len(left_in)+1]
        right_pre = preorder[len(left_in)+1:]
        return middle, right_in, left_in, right_pre, left_pre

```