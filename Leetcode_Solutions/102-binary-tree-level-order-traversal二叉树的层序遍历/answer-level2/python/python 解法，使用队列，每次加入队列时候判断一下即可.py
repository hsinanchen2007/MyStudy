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
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        vc,re = [],[]
        if root==None:
            return []
        vc.append(root)
        while len(vc)>0:
            re1 = []
            le = len(vc)
            for i in range(le):
                m = vc.pop(0)
                re1.append(m.val)
                if m.left:
                    vc.append(m.left)
                if m.right:
                    vc.append(m.right)
            re.append(re1)
        return re
```