### 解题思路
根据递归的思想，先设置一个f(node)函数，求解以node为根节点，并经过node的最长同值路径。
先求出以左右节点为根节点并经过他们的最长同值路径，然后判断node.val和左右节点的值：
相等了，给该值+1,不相等直接置0，因为要经过该节点。
总体来说，遍历每一个节点，求出以该节点为根并经过他的最长路径，然后再在这些值里面取最大值
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.res =0 
    def longestUnivaluePath(self, root: TreeNode) -> int:
        
        def maxLen(node):
            if node == None:
                return 0
            left = maxLen(node.left)
            right = maxLen(node.right)
            if node.left:
                left = left + 1 if node.left.val == node.val else 0
            if node.right:
                right = right + 1 if node.right.val == node.val else 0

            self.res = max(self.res, left+right)
            return max(left, right)
        maxLen(root)
        return self.res


```