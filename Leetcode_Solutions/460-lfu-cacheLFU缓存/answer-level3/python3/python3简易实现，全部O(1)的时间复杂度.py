```python
from collections import defaultdict


class Node:
    def __init__(self, _key, _val, _freq=1, _next=None, _prev=None):
        self.key = _key
        self.val = _val
        self.freq = _freq  # 频率attribute
        self.next = _next
        self.prev = _prev


class DoubleList:
    def __init__(self):
        self.head = Node(-1, -1, -1)
        self.tail = Node(-1, -1, -1)  # 哨兵节点
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0

    def addFirst(self, node_x):
        """向双向链表头部添加节点"""
        node_x.next = self.head.next
        node_x.prev = self.head
        self.head.next.prev = node_x
        self.head.next = node_x
        self.size += 1

    def remove(self, node_x):
        """调用这个函数一定是非空状态"""
        node_x.prev.next = node_x.next
        node_x.next.prev = node_x.prev
        self.size -= 1

    def removeLast(self):
        """删除最后一个节点，并返回"""
        if self.size == 0:
            return None

        last_node = self.tail.prev
        self.remove(last_node)
        return last_node

    def isEmpty(self):
        return self.size == 0


class LFUCache:

    def __init__(self, capacity: int):
        self.map = {}  # 和LRU那个map是一样的功能，存<key, Node>
        self.freq_map = defaultdict(DoubleList)  # 记录频率的map，相比LRU cache多出来的
        # 注意frep_map的key为整数，代表了频次，value为DoubleList()
        self.capacity = capacity
        self.size = 0
        self.min_freq = 1

    def get(self, key: int) -> int:
        if key not in self.map:
            return -1
        val = self.map[key].val
        self.put(key, val)
        return val

    def put(self, key: int, value: int) -> None:
        # key本身就存在，不用维护self.size，因为只有维护操作
        if key in self.map:
            exist_node = self.map[key]
            new_freq = exist_node.freq + 1
            new_node = Node(key, value, new_freq)
            self.freq_map[exist_node.freq].remove(exist_node)
            # 下面的判断条件第一个条件一定不能省！！debug一个小时！！！！！fuck!
            # 因为删除为后为空并不一定是最小freq的那组，所以要加判断
            if exist_node.freq == self.min_freq and self.freq_map[exist_node.freq].isEmpty():
                self.min_freq = new_freq
            self.freq_map[new_freq].addFirst(new_node)
            self.map[key] = new_node
        else:  # key存在
            if self.capacity == 0:  # 特例判别
                return 

            if self.size == self.capacity:
                # 直接remove最后一个，和频次一样时，删除最不常用的逻辑保持一直
                last_node = self.freq_map[self.min_freq].removeLast()
                self.map.pop(last_node.key)
                self.size -= 1
            new_node = Node(key, value)
            self.freq_map[1].addFirst(new_node)
            self.map[key] = new_node
            self.min_freq = 1  # 维护一下min_freq
            self.size += 1
```