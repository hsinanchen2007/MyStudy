### 解题思路
我的思路：考察的是二叉搜索树中序遍历，是一个递增序列。
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)


### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        lists = []
        def helper(root):
            if not root:
                return None
            helper(root.left)
            lists.append(root.val)
            helper(root.right)
        helper(root)
        sums = 0
        mark = 0
        for x in lists:
            if x == L:
                sums += x 
                mark = 1
            elif x == R:
                sums += x
                break
            elif mark == 1:
                sums += x
        return sums

```