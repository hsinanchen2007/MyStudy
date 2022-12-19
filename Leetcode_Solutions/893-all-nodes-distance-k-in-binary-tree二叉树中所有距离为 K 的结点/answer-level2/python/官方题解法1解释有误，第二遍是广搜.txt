### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) -> List[int]:
        def dfs(cur,parent):
            if cur:
                cur.parent = parent
                dfs(cur.left,cur)
                dfs(cur.right,cur)
        
        dfs(root,None)
        queue,seen = [(target,0)],[target]
        while queue:
            if queue[0][1] ==K:
                return [node.val for node,distance in queue ]
            node,distance = queue.pop(0) #pop after!
            for node in (node.parent,node.left,node.right): # node not None
                if node and (node not in seen):
                    queue.append((node,distance+1))
                    seen.append(node)
        return []  #aaaaa


```