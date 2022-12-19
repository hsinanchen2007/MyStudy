### 解题思路
执行用时 :232 ms, 在所有 Python3 提交中击败了64.68%的用户
内存消耗 :22.7 MB, 在所有 Python3 提交中击败了5.13%的用户

1. 双向链表，每个节点有key val prev nxt四个属性
2. 哈希表cache = {}，其中的key值与双向链表节点的key值对应，value是对应的链表节点
3. get()的时候，直接从哈希表中取值复杂度O(1)
4. put()的时候，向链表中插入/删除/移动元素复杂度O(1)
5. 注意，add_head、delete_node、move_to_head、pop_tail等函数都只是改变了链表的连接关系，从cache中添加/删除节点的操作在put()中

### 代码

```python3
class DLinkedNode:
    def __init__(self, key, val, prev=None, nxt=None):
        self.key = key
        self.val = val
        self.prev = prev
        self.nxt = nxt


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.size = 0
        self.head = DLinkedNode(0, 0)
        self.tail = DLinkedNode(0, 0)

        self.head.nxt = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        node = self.cache.get(key, None)
        if not node:
            return -1
        self.move_to_head(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        node = self.cache.get(key)
        if node:
            self.move_to_head(node)
            self.cache[key].val = value
        else:
            self.size += 1
            if self.size > self.capacity:
                old_node = self.pop_tail()
                del self.cache[old_node.key]
            new_node = DLinkedNode(key, value)
            self.add_head(new_node)
            self.cache[key] = new_node

    def add_head(self, new_node):
        prev_node = self.head
        nxt_node = self.head.nxt

        new_node.prev = prev_node
        new_node.nxt = nxt_node

        prev_node.nxt = new_node
        nxt_node.prev = new_node

    def pop_tail(self):
        old_node = self.tail.prev
        self.delete_node(old_node)
        return old_node

    def delete_node(self, node):
        prev_node = node.prev
        nxt_node = node.nxt

        prev_node.nxt = nxt_node
        nxt_node.prev = prev_node

    def move_to_head(self, node):
        self.delete_node(node)
        self.add_head(node)



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```