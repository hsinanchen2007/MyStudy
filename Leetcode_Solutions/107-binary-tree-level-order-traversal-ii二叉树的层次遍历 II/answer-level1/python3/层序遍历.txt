### 解题思路

正着层序遍历，然后倒着输出

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root:
            return []
        
        s = [root]
        t = []
        while len(s):
            tmp = []
            for item in s:
                tmp.append(item.val)
                if item.left:
                    t.append(item.left)
                if item.right:
                    t.append(item.right)
            res.append(tmp)
            s = t
            t = []
        return res[::-1]
```