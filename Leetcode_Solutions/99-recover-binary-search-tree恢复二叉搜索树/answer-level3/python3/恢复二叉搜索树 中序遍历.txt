### 解题思路
中序遍历, 缓存两个异常点的**值, 最后只交换值就好了**,
看评论第一很清楚思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        t1 = t2 = pre = None
        def solve(n):
            nonlocal t1, t2, pre
            if not n: return
            solve(n.left)
            if pre and n.val<pre.val:
                t1 = pre if not t1 else t1
                t2 = n
            pre = n # 这一步很关键, 记录中序遍历的上一个node
            solve(n.right)
        solve(root)
        t1.val, t2.val = t2.val, t1.val
```