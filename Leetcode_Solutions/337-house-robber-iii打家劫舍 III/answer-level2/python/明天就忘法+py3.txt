### 解题思路
此处撰写解题思路

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

        def helper(Newroot:TreeNode):
            if not Newroot:
                return [0,0]
            llist=helper(Newroot.left)
            rlist=helper(Newroot.right)

            res=[max(llist)+max(rlist),Newroot.val+llist[0]+rlist[0]]
            return res
        return max(helper(root))
```