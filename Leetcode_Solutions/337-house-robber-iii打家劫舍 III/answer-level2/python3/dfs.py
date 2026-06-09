### 解题思路
每个节点返回两个值，第一个值为偷这家和不偷这家的最大值，第二个值是不偷这家，偷下两家的值。
![...%8A%AB%E8%88%8D3.MP4](28132e10-040c-45be-86a7-0701d076b31c)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        def helper(node):
            if node == None:
                return 0, 0
            left,prel = helper(node.left)
            right, prer = helper(node.right)
            return max(prel+prer+node.val,left+right),left+right
        return helper(root)[0]
```