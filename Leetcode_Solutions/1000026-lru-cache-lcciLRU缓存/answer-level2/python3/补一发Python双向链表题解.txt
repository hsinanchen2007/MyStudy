```
class Node:

    def __init__(self, k, v):
        self.key = k
        self.val = v
        self._prev = None
        self._next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.store = {}
        # 预设一个头尾节点，后续插入时不要判空的情况
        self.head = Node('h', -1)
        self.tail = Node('t', -1)
        self.head._next = self.tail
        self.tail._prev = self.head
        self.cap = capacity

    def insert_after(self, target, node):
        # 将一个新节点插入到某节点的后面
        node._next = target._next
        node._prev = target

        target._next._prev = node
        target._next = node

    def move_to_head(self, node):
        # 将已存在的节点插入到头结点后面
        node._prev._next = node._next
        node._next._prev = node._prev

        node._next = self.head._next
        node._prev = self.head

        self.head._next = node
        node._next._prev = node
        
    def pop(self):
        # 待删除的节点
        res = self.tail._prev
        res._prev._next = self.tail
        self.tail._prev = res._prev

        res._prev = None
        res._next = None

        return res

    def get(self, key: int) -> int:
        item = self.store.get(key, -1)
        if item != -1:
            self.move_to_head(item)
            return item.val
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.store:
            item = self.store[key]
            item.val = value
            self.move_to_head(item)
            return
        if len(self.store) == self.cap:
            poped = self.pop()
            del self.store[poped.key]
        # 插入新节点
        node = Node(key, value)
        self.insert_after(self.head, node)
        self.store[key] = node
```