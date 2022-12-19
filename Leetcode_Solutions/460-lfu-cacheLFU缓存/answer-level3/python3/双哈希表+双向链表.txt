### 解题思路
和LRU思路差不多，双向链表每个节点的值为`[key, value, freq]`，其中freq初始值为1。出现频率一致的key在同一个双向链表上。
哈希表`freq_map`存频率及对应频率的链表，形式如下：

```bash
freq_map = {
    1: head <-> node1 <-> node2 <-> ... ,
    2: head <-> node3 <-> node4 <-> ... ,
    3: head <-> node5 <-> node6 <-> ... ,
    ...
}
```

哈希表 `key_map`存键和节点的对应关系，形式如下：

```bash
key_map = {
    key1: node1,
    key2: node2,
    key3: node3,
    ...
}
```
双向链表固定从head后面插入新节点，这样删除最最不经常使用的节点只需要从链表尾部删除即可。为了在O(1)时间删除
最不经常使用节点，我们还需要维护`min_freq`。

LFU get逻辑如下：

1. 如果key不在key_map中，直接返回-1；
2. 通过key_map[key]获取节点；
3. 在当前节点所在链表删除节点；
4. 节点freq增加1；
5. 在freq_map[node.freq+1]的链表上插入节点；
6. 更新min_freq。如果节点狭义后，min_freq所属链表为空，则更新min_freq为node.freq。

LFU put逻辑如下：

1. 如果LRU容量为0，直接返回；
2. 如果key在key_map中，则先更新节点的值，之后操作同get逻辑；
3. 如果为新增节点，先在key_map存储该节点信息；
4. 然后在node.freq所属链表插入该节点，同时LFU的长度增加1；
5. 如果 LFU 长度超过容量，则调用min_freq所在链表的deleted_oldest方法删除节点，并同时在key_map也删除该节点；
6. 删除成功后LFU 长度减少 1；
7. 更新min_freq为node.freq。

### 代码

```python3
from collections import defaultdict


class Node:
    def __init__(self, key, val=None, freq=1):
        self.key = key
        self.val = val
        self.freq = freq
        self.next = None
        self.prev = None


class Link:
    def __init__(self):
        self.head = Node(0, 0)
        self.head.next = self.head
        self.head.prev = self.head
        self.size = 0

    def insert(self, node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node
        self.size += 1

    def delete(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        self.size -= 1
        return node.key

    def delete_oldest(self):
        if self.head.prev is not self.head:
            return self.delete(self.head.prev)


class LFUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.size = 0
        self.key_map = {}
        self.freq_map = defaultdict(Link)
        self.min_freq = 0

    def down(self, node):
        link = self.freq_map[node.freq]
        link.delete(node)
        node.freq += 1
        self.freq_map[node.freq].insert(node)
        if self.freq_map[self.min_freq].size == 0:
            self.min_freq = node.freq

    def get(self, key):
        try:
            node = self.key_map[key]
            self.down(node)
            return node.val
        except KeyError:
            return -1

    def put(self, key, value):
        if self.capacity == 0:
            return
        try:
            node = self.key_map[key]
            node.val = value
            self.down(node)
        except KeyError:
            node = Node(key, value)
            self.key_map[key] = node
            self.freq_map[node.freq].insert(node)
            self.size += 1
            if self.size > self.capacity:
                deleted = self.freq_map[self.min_freq].delete_oldest()
                self.key_map.pop(deleted, None)
                self.size -= 1
            self.min_freq = node.freq
```