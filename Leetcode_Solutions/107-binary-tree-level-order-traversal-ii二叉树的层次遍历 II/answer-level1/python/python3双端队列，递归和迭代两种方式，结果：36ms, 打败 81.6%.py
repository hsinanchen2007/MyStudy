### 解题思路

用结果列表使用双端队列，是考虑可以appendleft头部插入(  appendleft插入方式复杂度复杂度O(1)  )，
这样可以替代insert插入（  insert插入方式复杂度O(N)  )。


法1，迭代BFS，


```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        res=deque([])
        cur_level=[root]
        while cur_level:
            tmp=[]
            next_level=[]
            for node in cur_level:
                tmp.append(node.val)
                if node.left:  next_level.append(node.left)
                if node.right: next_level.append(node.right)
            res.appendleft(tmp)
            cur_level=next_level
        return list(res)
```

法2， 递归DFS

```
from collections import deque
class Solution:
    def levelOrderBottom(self, root):
        res=deque([])
        def helper(root,depth):
            if not root: return res
            if depth==len(res):#>=
                res.appendleft([])
            res[-depth-1].append(root.val)
            helper(root.left,depth+1)
            helper(root.right,depth+1)          
        helper(root,0)
        return list(res)
```
