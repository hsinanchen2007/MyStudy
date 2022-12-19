### 解题思路
关键是写一个balance函数，计算每个节点的bal = r+l+node.val-1（因为1是平衡的，每个节点自己需要一个）

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distributeCoins(self, root: TreeNode) -> int:

        res = 0

        def balance(node):
            nonlocal res  
            if node is None:
                return 0
            l_balance = balance(node.left)
            r_balance = balance(node.right)

            res += abs(l_balance)+abs(r_balance)

            return l_balance + r_balance + node.val -1

        balance(root)
        return res


```