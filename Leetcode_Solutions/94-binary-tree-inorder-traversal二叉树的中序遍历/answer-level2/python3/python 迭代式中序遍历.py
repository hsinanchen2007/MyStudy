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
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        va,sta = [],[]
        p = root
        while((p!=None)|(len(sta)>0)):
            while(p):
                sta.append(p)
                p = p.left
            p = sta[-1]
            sta.pop()
            va.append(p.val)
            p = p.right
        return va
```