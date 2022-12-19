### 解题思路
在102二叉树的层次遍历的基础上改进，这更像是标准BFS（visited并不必要）

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        #102二叉树的层次遍历的升级版--BFS
        from collections import deque
        if not root:return []
        queue=deque()
        queue.append(root)
        res=[]
        level=0
        while queue:
            res.append([])
            level_len=len(queue)
            for i in range(level_len):
                curNode=queue.popleft()
                res[level].append(curNode.val)
                for cNode in curNode.children:
                    if cNode:
                        queue.append(cNode)
            level+=1
        return res


```