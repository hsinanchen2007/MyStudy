瞎写的求鉴定
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        a = []
        if not root:
            return a
        else:
            cur = [root]
            while cur:
                a.append([])
                tmp = []
                for i in cur:
                    a[-1].append(i.val)
                    if i.left:
                        tmp.append(i.left)
                    if i.right:
                        tmp.append(i.right)
                cur = tmp
            return a[::-1]
```