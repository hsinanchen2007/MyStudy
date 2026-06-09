### 解题思路

按照官网的提示自己实现了一下，对每一个freq构造一个双向列表，用两个hash表，一个用于直接访问到点，另一个用于访问每个freq对应的节点

同时维护一个min_freq,用于删除元素。修改min_freq只可能有两种情况:
- 访问了一个key，这个key的freq为min_freq对应的freq加了1 原来所在的链表为空了，这个时候需要将min_freq+1
- 新加了一个key，这个时候min_freq为1


时间复杂度`O(1)`, 空间复杂度为`O(n)`

### 代码

```python3
class Node:
    """
    双向链表节点类
    """
    def __init__(self, key = None, value = None, freq = 0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None
        self.freq = freq
        
class LinkList:
    """
    双向链表类
    """
    def __init__(self):
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def add_from_head(self, node):
        """
        向链表头添加一个节点
        """
        node.next = self.head.next
        node.prev = self.head
        node.prev.next = node
        node.next.prev = node
    
    def delete_from_tail(self):
        """
        删除链表尾部的一个节点
        """
        t = self.tail.prev
        self.delete(self.tail.prev)
        return t
        
    def delete(self, node):
        """
        将某个节点从其所在的链表中删除
        """
        node.prev.next = node.next
        node.next.prev = node.prev
        

class LFUCache:

    def __init__(self, capacity: int):
        self.d = {}
        self.freq = {}
        self.min_freq = 0
        self.cap = capacity
        self.freq[1] = LinkList()
        
    def update(self, node):
        """
        访问完一个节点之后对这个节点更新
        增加这个节点的freq，维护min_freq
        """
        self.freq[node.freq].delete(node)   #  将节点从之前的链表中删除
        node.freq += 1
        if node.freq not in self.freq:      # 将节点添加到新的链表中
            self.freq[node.freq] = LinkList()
        self.freq[node.freq].add_from_head(node)
        if self.freq[self.min_freq].head.next == self.freq[self.min_freq].tail:  # 维护min_freq
            self.min_freq += 1
        
    def get(self, key: int) -> int:
        """
        获取某个key对应的value
        """
        if key in self.d:
            self.update(self.d[key])
            return self.d[key].value
        else:
            return -1
        
    def put(self, key: int, value: int) -> None:
        """
        添加某个元素
        """
        if self.cap == 0:
            return 
        
        if key in self.d:
            self.d[key].value = value
            self.update(self.d[key])
        else:
            if len(self.d) == self.cap:
                t = self.freq[self.min_freq].delete_from_tail()
                del self.d[t.key]
            a = Node(key, value, 1)
            self.freq[1].add_from_head(a)
            self.min_freq = 1
            self.d[key] = a


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```