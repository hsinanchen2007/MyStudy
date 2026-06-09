### 解题思路
中序遍历，再构造链表

### 代码

```python3
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return
        from itertools import tee
        def dfs(node):
            if node:
                yield from dfs(node.left)
                yield node
                yield from dfs(node.right)
        nodelist = list(dfs(root))
        # dummy指向root
        dummy = Node(-1, None, None)
        nodelist.insert(0, dummy)
        a, b = tee(nodelist)
        next(b) 
        for f, s in zip(a, b):
            f.right = s
            s.left = f
        # 将 dummy 删掉   
        dummy.right.left = s
        s.right = dummy.right
        return dummy.right
```