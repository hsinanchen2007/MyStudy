### 解题思路
对于二叉数的递归，我们只要想清楚当前的root需要干什么就行！如下图
![image.png](https://pic.leetcode-cn.com/085c8bc12439e3af744d9b6029daac7b87388af449b9f0f3c73149b350edd5d2-image.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:

        def dfs(root, L, R):
            if root is None:
                return 
            if root.val > R:
                root = dfs(root.left, L, R)
            elif root.val < L:
                root = dfs(root.right, L, R)
            else:
                root.left = dfs(root.left, L, R)
                root.right = dfs(root.right, L , R)
            return root
        
        return dfs(root, L, R)

```