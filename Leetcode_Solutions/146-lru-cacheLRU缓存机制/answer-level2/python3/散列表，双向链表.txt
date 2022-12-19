### 解题思路

散列表和双向链表联合使用

使用散列表可以在`O(1)`的时间利用`key`找到对应的节点，双向链表维护的是节点的访问次序，当访问了一个节点

将其在双向链表中删除，并添加到链表头或者链表尾中， 容量满之后只需要删除链表头或者链表尾的元素即可


时间复杂度`O(1)`， 空间复杂度`O(n)`


### 代码

```python3
class LinkNode:

    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None
        self.ok = True


class LRUCache:

    def __init__(self, capacity: int):
        '''
        使用字典来记录数据是否存在，字典中存储的值是节点，完成O(1)时间的查询
        利用双向链表来组织数据，完成O(1)时间的插入和删除
        '''
        self.record = {}
        self.size = 0
        self.capacity = capacity
        self.head = LinkNode(None, None)
        self.tail = LinkNode(None, None)
        self.head.next = self.tail
        self.tail.prev = self.head        
    

    def _add_head(self, node:LinkNode) -> None:
        '''
        将一个节点插入到头结点之后的位置
        '''
        node.prev = self.head
        node.next = self.head.next
        self.head.next = node
        node.next.prev = node
    
    def _delete_node(self, node:LinkNode) -> None:
        '''
        删除一个节点
        '''
        node.prev.next = node.next
        node.prev.next.prev = node.prev

    def get(self, key: int) -> int:
        '''
        获取一个元素
        '''
        item = self.record.get(key, None)
        if item and item.ok:
            self._delete_node(item)
            self._add_head(item)
            return item.value
        else:
            return -1
            
    def put(self, key: int, value: int) -> None:
        '''
        新增数据
        '''
        item = self.record.get(key, None)
        if item:
            item.value = value
            self.get(key)
        else:
            temp = LinkNode(key, value)
            self.record[key] = temp
            if self.size == self.capacity:
                temp1 = self.tail.prev
                del self.record[temp1.key]
                self._delete_node(temp1)
                self._add_head(temp)
            else:
                self._add_head(temp)
                self.size += 1
    
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```