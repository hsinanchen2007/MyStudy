### 解题思路
此处撰写解题思路

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
        if not root :
            return root
        # 按照层次遍历将结点放置在一个列表中
        leftqueue,rightqueue = [],[]
        rightqueue.append(root)
        while rightqueue :
            out = rightqueue.pop(0)
            leftqueue.append(out)
            if out.left :
                rightqueue.append(out.left)
            if out.right :
                rightqueue.append(out.right)
        # 对结点右指针进行填充
        layer = 1
        while leftqueue :
            left  = leftqueue[ : 2 ** (layer - 1)]
            leftqueue = leftqueue[2 ** (layer - 1) : ]
            n = len(left)
            for i in range(n) :
                if i + 1 <= n - 1 :
                    left[i].next = left[i + 1]
            layer += 1
        return root

```