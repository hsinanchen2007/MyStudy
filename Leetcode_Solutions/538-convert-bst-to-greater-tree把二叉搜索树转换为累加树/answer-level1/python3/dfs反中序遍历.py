### 解题思路
#思路就是反中序遍历
#就是说遍历出来的结果是从大到小,遇到一个节点就将其加入cur_total中
#并cur_total赋值给当前节点..
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        cur_total = 0
        def helper(n):
            nonlocal cur_total
            if n:
                helper(n.right)
                cur_total += n.val
                n.val = cur_total
                helper(n.left)
                return n
        return helper(root)
```