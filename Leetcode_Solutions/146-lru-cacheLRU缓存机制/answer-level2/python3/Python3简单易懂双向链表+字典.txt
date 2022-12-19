### 解题思路
get要O(1), put要O(1), 那肯定得有一个字典
要保持好一个顺序, 用来淘汰尾部的元素. 而且这个淘汰删除操作要O(1), 这说明得有链表.
为了put操作实现了move_to_head函数. 这个函数本身需要链表的前后结点容易维护, 因此链表得要是双向链表(prev, next).
综上, 我们需要在LRUCache这个类内部维护两套数据结构, 一个是mapping, 一个是链表llist

### 代码

```python3
# 本质上就维护一个字典和一个双向链表

class Node:
    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None
    
    def __str__(self):
        return self.__repr__()

    def __repr__(self):
        return "node_" + str(self.key)

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.mapping = {}
        self.head = Node(None, None)  # llist头节点和尾结点没有存真正的数据.
        self.tail = Node(None, None)
        self.head.next = self.tail
        self.tail.prev = self.head
    
    def _pop_tail(self):
        tail_node = self.tail.prev
        if tail_node is not None:
            tail_node.prev.next = self.tail  # 别漏了删除tail_node前置节点和自己的连接关系, 
            self.tail.prev = tail_node.prev
        return tail_node
    
    def _move_to_head(self, node: Node):
        # 处理原先所在位置
        if node.prev is not None:
            node.prev.next = node.next
        if node.next is not None:
            node.next.prev = node.prev
        # 处理原先的头结点
        if self.head.next is not None:
            self.head.next.prev = node
        node.next = self.head.next
        node.prev = self.head
        self.head.next = node

    def show(self):
        """
        用来debug
        """
        p = self.head.next
        l = []
        while p:
            l.append(p.key)
            p = p.next
        return "llist:" + str(l) + ", map:" + str(self.mapping)

    def get(self, key: int) -> int:
        if key not in self.mapping:
            return -1
        node = self.mapping[key]
        self._move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if key in self.mapping:
            node = self.mapping[key]
            node.value = value
            self._move_to_head(node)
            return
        node = Node(key, value)
        self.mapping[key] = node
        self._move_to_head(node)
        if len(self.mapping) > self.capacity:
            tail_node = self._pop_tail()
            if tail_node is not None and tail_node.key is not None:
                del self.mapping[tail_node.key]

    

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```