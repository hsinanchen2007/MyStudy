### 解题思路
参考了大佬的方法

### 代码

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        # # 层遍历方法
        # q = [(0, root)]
        # while q:
        #     layer, node = q.pop(0)
        #     if node:
        #         if node.left:
        #             q.append((layer+1, node.left))
        #         if node.right:
        #             q.append((layer+1, node.right))
        #         if q and q[0] and q[0][0] == layer:
        #             node.next = q[0][1]
        # return root
        # 常数空间方法
        tmp = root
        while True:
            cur = tmp
            if cur is None:
                break
            while cur:
                if cur.left:
                    cur.left.next = cur.right
                    if cur.next:
                        cur.right.next = cur.next.left
                cur = cur.next
            tmp = tmp.left
        return root
```