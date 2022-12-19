### 解题思路
题目几乎一模一样，代码原封不动直接拿过来就可以
![image.png](https://pic.leetcode-cn.com/0d62ec0d3223ac043addac82085c52fbeef70dc02f504e425ddd4521d27e77ec-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        def count_depth(node):
            if node is None:
                return 0
            if node.left is None and node.right is None:
                return 1
            return max(count_depth(node.left),count_depth(node.right))+1

        def check_balance(node):
            if node is None:
                return True
            if node.left is None and node.right is None:
                return True     
            left_depth=count_depth(node.left)
            right_depth=count_depth(node.right)
            a=abs(left_depth-right_depth)<=1
            return a and check_balance(node.left) and check_balance(node.right)
        return check_balance(root)

```