### 解题思路类似于上一题，只不过要多一个判断，找到下一个有子节点的兄弟节点，注意要先遍历右节点，再遍历左节点，不然每次寻找下一个兄弟节点时，同级的兄弟链表会不全

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
        if not root:
            return root
        if root.left and root.right:
            root.left.next  = root.right
        elif root.left and not root.right:
            xiongdi = root.next
            while xiongdi:
                if xiongdi.left:
                    root.left.next = xiongdi.left
                    break
                elif xiongdi.right:
                    root.left.next = xiongdi.right
                    break
                else:
                    xiongdi = xiongdi.next
        if (not root.left and root.right) or root.right:
            xiongdi = root.next
            while xiongdi:
                # print(xiongdi.val)
                if xiongdi.left:
                    root.right.next = xiongdi.left
                    break
                elif xiongdi.right:
                    root.right.next = xiongdi.right
                    break
                else:
                    xiongdi = xiongdi.next
        self.connect(root.right)
        self.connect(root.left)
        return root
```