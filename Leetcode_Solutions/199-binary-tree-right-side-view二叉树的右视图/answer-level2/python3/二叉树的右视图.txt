### 解题思路
普通的广度优先搜索

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        res=[]
        stack=[root]
        while stack:
            rs=[]
            ns=[]
            for i in stack:
                rs.append(i.val)
                if i.left!=None:
                    ns.append(i.left)
                if i.right!=None:
                    ns.append(i.right)
            res.append(rs[-1])
            stack=ns
        return res
```