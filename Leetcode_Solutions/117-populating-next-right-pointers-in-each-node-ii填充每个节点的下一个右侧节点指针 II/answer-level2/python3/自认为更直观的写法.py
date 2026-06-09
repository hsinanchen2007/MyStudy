### 解题思路
思路和官方差不多，但是官方的写法一时get不到，按照自己的理解撸了一个，自我感觉还算直观，写上必要注释，供各位参考。

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
        leftmost = root
        while leftmost:
            cur = leftmost
            while cur:
                # 处理下一个节点，如果下一个节点没有左右子树，就一直找下下一个节点
                nxt = cur.next
                while nxt and not (nxt.left or nxt.right):
                    nxt = nxt.next
                # 没有下一个节点，设置完当前节点左右子树后直接结束循环
                if not nxt:
                    if cur.left and cur.right:
                        cur.left.next = cur.right
                    break
                # 存在下一个节点，按照当前节点是否有左右子树分别处理
                if cur.left and cur.right:
                    cur.right.next = nxt.left or nxt.right
                    cur.left.next = cur.right
                elif cur.left:
                    cur.left.next = nxt.left or nxt.right
                elif cur.right:
                    cur.right.next = nxt.left or nxt.right
                cur = nxt
            
            # 寻找下一层的最左节点
            while leftmost:
                if leftmost.left:
                    leftmost = leftmost.left
                    break
                elif leftmost.right:
                    leftmost = leftmost.right
                    break
                leftmost = leftmost.next
        return root
```