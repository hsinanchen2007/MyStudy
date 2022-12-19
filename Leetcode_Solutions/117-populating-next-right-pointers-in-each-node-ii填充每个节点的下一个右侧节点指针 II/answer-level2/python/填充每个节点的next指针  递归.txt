### 解题思路
关键1：
    #直到找到存在子节点的上层节点
    tmp = root.next
    while tmp and (not tmp.left and not tmp.right):
        tmp = tmp.next
关键2：
    #一定要先递归右节点，不然self.connect(root.left) 时父节点的跳线尚未连好
    self.connect(root.right)
    self.connect(root.left)

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root:
            if root.left:
                if root.right: # 有右节点
                    root.left.next = root.right
                else:
                    # 直到找到存在子节点的上层节点
                    tmp = root.next
                    while tmp and (not tmp.left and not tmp.right):
                        tmp = tmp.next
                    # 连上最近的节点
                    if tmp:
                        root.left.next = tmp.left if tmp.left else tmp.right
            if root.right:
                # 直到找到存在子节点的上层节点
                tmp = root.next
                while tmp and (not tmp.left and not tmp.right): 
                    tmp = tmp.next
                if tmp:
                    root.right.next = tmp.left if tmp.left else tmp.right
            # 一定要先递归右节点
            self.connect(root.right)
            self.connect(root.left)
        return root
```
时间复杂度O(1)