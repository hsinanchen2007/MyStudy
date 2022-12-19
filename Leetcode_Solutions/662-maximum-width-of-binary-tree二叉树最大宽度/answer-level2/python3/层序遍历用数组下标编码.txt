通过队列，对每一层的节点按照层数放到记录数组中，并且通过下标表示法来记录编号。

遍历记录数组，求最大值即可。

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
        
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root: return 0
        q = [(0, root)]
        hsh = [q]
        while q:
            cur = []
            for (i, rt) in q:
                if rt.left:
                    cur.append((i * 2, rt.left))
                if rt.right:
                    cur.append((i * 2 + 1, rt.right))    
            q = cur    
            hsh.append(cur)
            
        ans = 1    
        for i in range(len(hsh)):
            if len(hsh[i]) > 0:
                # print(i, hsh[i][-1][0] - hsh[i][0][0] + 1)    
                ans = max(ans, hsh[i][-1][0] - hsh[i][0][0] + 1) 
        return ans        
```