### 解题思路
稀里糊涂就过了，思路就是找左边节点和右边节点的最大值，加起来就是最长直径。
然后迭代每个点


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

        def depth(node):
            if node == None:
                return 0
            left = depth(node.left) + 1
            right = depth(node.right) + 1
            return max(left , right)
        
        def dia(node):
            if node == None:
                return 0
            ans = depth(node.left) + depth(node.right)
            l = dia(node.left)
            r = dia(node.right)
            return max(ans , l , r)
    
        ans = dia(root)

        return ans


```