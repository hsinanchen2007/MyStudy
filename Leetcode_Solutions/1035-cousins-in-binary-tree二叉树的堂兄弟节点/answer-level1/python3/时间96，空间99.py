使用队列遍历树；
使用一个列表list记录x、y的深度与父亲节点；
当list长度为2时，break退出，以便节省不必要的时间；
当x的深度==y的深度并且x的父亲节点!=y的父亲节点时，返回True，否则返回False。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        com = []
        if root.val == x or root.val == y:
            com.append((0,None))
        de = deque()
        de.append((0,root))
        while de:
            depth,node = de.popleft()
            if node.left:
                if node.left.val == x or node.left.val == y:
                    com.append((depth+1,node))
                de.append((depth+1,node.left))
            if node.right:
                if node.right.val == x or node.right.val == y:
                    com.append((depth+1,node))
                de.append((depth+1,node.right))
            if len(com) == 2:
                break
        print(com)
        if com[0][0] == com[1][0] and com[0][1] != com[1][1]:
            return True
        else:
            return False
```