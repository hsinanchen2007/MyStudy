### 解题思路
使用BFS，一层层向前推进的遍历树的节点，每进一层，记录distance（等于父节点distance+1）
queue最后返回的节点就是离树根最远的节点，它的distance就是树的最大深度

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        queue =[]
        if root:
            queue.insert(0,(root,1))
        else:
            return 0
        while queue:
            cur,curdis = queue.pop()
            if cur.left:
                queue.insert(0,(cur.left,curdis+1))
            if cur.right:
                queue.insert(0,(cur.right,curdis+1))
        return curdis
```