### 解题思路
dfs

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import string
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        """
        dfs pre order
        :param root:
        :return:
        """
        res = []

        def dfs(node: TreeNode, ll: List[int]):
            if not node:
                return
            ll.append(node.val)
            if not node.left and not node.right:
                res.append(ll)
                return
            dfs(node.left, ll[:])
            dfs(node.right, ll[:])

        dfs(root, [])
        n = 0
        for r in res:
            print(r)
            s = ""
            for rr in r:
                print(rr)
                s += str(rr)
            n += int(s)
        return n
```