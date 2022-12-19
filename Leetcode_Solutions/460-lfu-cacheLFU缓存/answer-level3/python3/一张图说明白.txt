## 思路:

一张图说明白！

![image-20200405214800495.png](https://pic.leetcode-cn.com/61423eef7863d87c25bc77381e29504d91ad342234ca9b991e0c9046ca03533a-image-20200405214800495.png)


准备两个字典，

1. `key`与`freq`映射，为了找`key`在哪个频率下；
2. `key`与`value`映射，为了找`key`对应的`valu`e值，这个需要一个有序字典`OrderedDict`，为了好弹出同一个频率下，最开始加入的key（当然是容量不够，需要弹出的时候）

对于第二个字典，可以使用python自带库，也可以使用双向链表实现

思路一：用`python`内建有序字典`OrderedDict`实现。

思路二：双向链表，第一个字典就是`key`对应`node`的位置。

## 代码:

思路一：

```python
class LFUCache:

    def __init__(self, capacity: int):
        from collections import OrderedDict, defaultdict
        self.freq = defaultdict(OrderedDict)
        self.key_to_freq = {}
        self.capacity = capacity
        self.min_freq = 0

    def get(self, key: int) -> int:
        if key not in self.key_to_freq:
            return -1
        key_freq = self.key_to_freq[key]
        res = self.freq[key_freq].pop(key)
        if not self.freq[key_freq] and key_freq == self.min_freq:
            self.min_freq += 1
        self.freq[key_freq + 1][key] = res
        self.key_to_freq[key] = key_freq + 1
        return res

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0: return
        # key 本身就在其中
        if key in self.key_to_freq:
            key_freq = self.key_to_freq[key]
            self.freq[key_freq].pop(key)
            if not self.freq[key_freq] and key_freq == self.min_freq:
                self.min_freq += 1
            self.freq[key_freq + 1][key] = value
            self.key_to_freq[key] = key_freq + 1
        else:
            # key不在, 要弹出频率使用次数少的key
            if len(self.key_to_freq) == self.capacity:
                k, v = self.freq[self.min_freq].popitem(last=False)
                self.key_to_freq.pop(k)
            self.key_to_freq[key] = 1
            self.freq[1][key] = value
            self.min_freq = 1
```

思路二：

```python
# 定义节点
class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.freq = 1
        self.prev = self.next = None

# 定义双向链表
class DLinkedList:
    def __init__(self):
        self.dummy = Node(None, None)
        # 成环
        self.dummy.next = self.dummy
        self.dummy.prev = self.dummy
        self.size = 0

    def append(self, node: Node):
        # 尾插入, 加到双向链表尾部
        node.prev = self.dummy.prev
        node.next = self.dummy
        node.prev.next = node
        self.dummy.prev = node
        self.size += 1

    def pop(self, node: Node = None):
        if self.size == 0:
            return
        # 删除头部
        if node is None:
            node = self.dummy.next
        node.prev.next = node.next
        node.next.prev = node.prev
        self.size -= 1
        return node


class LFUCache:

    def __init__(self, capacity: int):
        from collections import defaultdict
        self.key_to_node = {}
        self.freq = defaultdict(DLinkedList)
        self.min_freq = 0
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.key_to_node:
            return -1
        node = self.key_to_node[key]
        node_freq = node.freq
        self.freq[node_freq].pop(node)
        if self.min_freq == node_freq and self.freq[node_freq].size == 0:
            self.min_freq += 1
        node.freq += 1
        self.freq[node.freq].append(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0: return
        if key in self.key_to_node:
            node = self.key_to_node[key]
            node_freq = node.freq
            self.freq[node_freq].pop(node)
            if self.min_freq == node_freq and self.freq[node_freq].size == 0:
                self.min_freq += 1
            node.freq += 1
            node.val = value
            self.freq[node.freq].append(node)
        else:
            if len(self.key_to_node) == self.capacity:
                node = self.freq[self.min_freq].pop()
                self.key_to_node.pop(node.key)
            node = Node(key, value)
            self.key_to_node[key] = node
            self.freq[1].append(node)
            self.min_freq = 1
```

