### 解题思路
单向链表＋哈希表实现LRU缓存
单向链表储存下一节点
哈希表node.key作为键，值为链表类型，储存当前节点的上一节点

### 代码

```python3
class LinkedList:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.dummy = LinkedList(None, None)
        self.tail = self.dummy
        self.capacity = capacity
        self.pre_dict = {}


    def get(self, key: int) -> int:
        if key not in self.pre_dict:
            return -1
        self.kickBack(key)
        node = self.pre_dict[key].next
        return node.val
    
    
    def kickBack(self, key):
        node = self.pre_dict[key].next
        if node == self.tail:
            return
        # kick the node
        self.pre_dict[key].next = node.next
        self.pre_dict[node.next.key] = self.pre_dict[key]
        # set at back
        self.pre_dict[key] = self.tail
        self.tail.next = node
        self.tail = node        
        

    def put(self, key: int, value: int) -> None:
        if key in self.pre_dict:
            node = self.pre_dict[key].next
            node.val = value
            self.kickBack(key)
            return
        node = LinkedList(key, value)
        self.pre_dict[node.key] = self.tail
        self.tail.next = node
        self.tail = node
        if len(self.pre_dict) > self.capacity:
            self.popFront()
        return


    def popFront(self):
        front_node = self.dummy.next
        self.dummy.next = front_node.next
        self.pre_dict[front_node.next.key] = self.dummy
        del self.pre_dict[front_node.key]
        return       


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```