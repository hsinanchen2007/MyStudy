### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        from collections import defaultdict
        d = defaultdict(lambda:Node(0)) # 任意键对应值都初始化为Node(0)
        d[None] = None # 添加头节点为空时的情况
        cur = head
        while cur:
            d[cur].val = cur.val # 键为原始节点，值为copy下的节点，将copy后的节点赋值
            d[cur].next = d[cur.next] # 将copy后节点的next值与键为cur.next节点对应的值连起来
            d[cur].random = d[cur.random] # 将copy后节点的random值与键为cur.random节点对应的值连起来
            cur = cur.next
        return d[head] # 返回头结点对应的值




```