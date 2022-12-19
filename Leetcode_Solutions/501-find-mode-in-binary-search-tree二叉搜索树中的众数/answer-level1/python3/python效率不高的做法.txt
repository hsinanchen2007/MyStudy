### 解题思路
先遍历，再counter

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        d = dict(collections.Counter(self.addNode(root, [])))
        ans = []
        
        m = max(d.values()) 
        for k, v in d.items():
            if(v == m):
                ans.append(k)
        return ans

    def addNode(self, node, s):
        if node:
            s.append(node.val)
            self.addNode(node.left, s)
            self.addNode(node.right, s)
        return s
```