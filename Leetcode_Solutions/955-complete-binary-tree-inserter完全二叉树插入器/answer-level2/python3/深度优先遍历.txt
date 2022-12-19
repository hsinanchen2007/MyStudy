### 解题思路
1. 把树的节点存到list里面
2. 把新的节点添加到list里面，根据新节点的索引整除2找到要插入的父节点，根据索引 % 2 来确定插入左右哪个节点。
3. 返回list的第一位，即根节点。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class CBTInserter:

    def __init__(self, root: TreeNode):
        self.lst = [None]
        q = deque([root])
        while q:
            n = q.pop()
            self.lst.append(n)
            if n.left:
                q.appendleft(n.left)
            if n.right:
                q.appendleft(n.right)

    def insert(self, v: int) -> int:
        node = TreeNode(v)
        self.lst.append(node)
        idx = len(self.lst) - 1
        p, c = divmod(idx, 2)
        if c == 0:
            self.lst[p].left = node
        elif c == 1:
            self.lst[p].right = node
        return self.lst[p].val

    def get_root(self) -> TreeNode:
        if len(self.lst) > 0:
            return self.lst[1]


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()
```