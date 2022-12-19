### 解题思路
1. 方法1: 使用自定义链表保存普通queue和最大queue(最大值位于tail), 得使用双向链表, 因为最大queue需要从head插入/tail删除, 而普通queue需要从head删除/tail插入, 只需要存正常的queue的head和tail, 以及maxqueue的mxhead, mxtail
2. 方法2: 使用deque代替自定义双向链表

### 代码

```python

# 方法1: 自定义双向链表
class ListNode():
    def __init__(self, v):
        self.val = v
        self.prev = None
        self.next = None


class MaxQueue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.mxhead = None
        self.mxtail = None

    def add_connection(self, pre, nex):
        pre.next = nex
        nex.prev = pre
        return (pre, nex)

    def remove_connection(self, node):
        nex = node.next
        node.next = None
        if node.next:
            node.next.prev = None
        return (node, nex)

    def max_value(self) -> int:
        if not self.mxtail:
            return -1
        return self.mxtail.val

    def push_back(self, value: int) -> None:
        if self.tail:
            _, self.tail = self.add_connection(self.tail, ListNode(value))
            while self.mxhead and self.mxhead.val < value:
                _, self.mxhead = self.remove_connection(self.mxhead)
            if not self.mxhead:
                self.mxhead = self.mxtail = ListNode(value)
            else:
                self.mxhead, _ = self.add_connection(ListNode(value), self.mxhead)
        else:
            self.head = self.tail = ListNode(value)
            self.mxhead = self.mxtail = ListNode(value)

    def pop_front(self) -> int:
        if not self.head:
            return -1
        res = self.head.val
        _, self.head = self.remove_connection(self.head)
        if not self.head:
            self.tail = None
            self.mxhead = self.mxtail = None
        else:
            if res == self.mxtail.val:
                self.mxtail, _ = self.remove_connection(self.mxtail.prev)
        return res
```

```python

# 方法2: 两个deque
class MaxQueue:
    def __init__(self):
        self.q = collections.deque([])
        self.mxq = collections.deque([])

    def max_value(self) -> int:
        if not self.mxq:
            return -1
        return self.mxq[-1]

    def push_back(self, value: int) -> None:
        self.q.append(value)
        while self.mxq and self.mxq[0] < value:
            self.mxq.popleft()
        self.mxq.appendleft(value)

    def pop_front(self) -> int:
        if not self.q:
            return -1
        res = self.q[0]
        self.q.popleft()
        if res == self.mxq[-1]:
            self.mxq.pop()
        return res
```