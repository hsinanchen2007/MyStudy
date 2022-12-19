### 解题思路
BFS的同时用哈希表记录一下每个节点的父节点和它的深度，最后比较如果不是同父节点，并且深度相等，返回True，否则False

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        deque=collections.deque()
        deque.append([root,-1,0])
        hashmap=collections.defaultdict(list)
        while deque:
            node,parentV,depth=deque.popleft()
            hashmap[node.val]=[parentV,depth]
            if node.left:
                deque.append([node.left,node.val,depth+1])
            if node.right:
                deque.append([node.right,node.val,depth+1])
        return hashmap[x][0]!=hashmap[y][0] and hashmap[x][1]==hashmap[y][1]
```


