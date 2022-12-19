### 解题思路
使用优先队列取所有里面最小值
有三部分：输出结果链表，优先队列，原链表s；优先队列作为输出和输入的连接，取出最小值后更新他们
语法部分：优先队列里面使用了小于号，需要对队列元素定义__lt__

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from queue import PriorityQueue

class qitem:
    def __init__(self, x, node):
        self.val = x
        self.node = node

    def __lt__(self, other):
        return self.val < other.val

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        head = ListNode(0)
        cur = head

        q = PriorityQueue()
        for l in lists:
            if l is not None:
                q.put(qitem(l.val, l))
        while not q.empty():
            qt = q.get()
            cur.next = qt.node
            cur = cur.next
            if qt.node.next is not None:
                q.put(qitem(qt.node.next.val, qt.node.next))

        return head.next
```