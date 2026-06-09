### 解题思路
在`functools`中有`lru_cache(maxnum)`装饰器实现LRU机制。
1.利用**有序字典**进行实现`from collections import OrderedDict`
*满足FIFO，将要查询/插入的元素移到队尾，如果出现容量不够的情况，删除队首。
2.利用**双向链表+哈希表**
*hash表存放{key,node}，便于搜索O(1)
*linkedlist维护顺序性，每搜索/插入元素，更新元素的位置到链表首，容量不够删链尾。便于插入O(1)


### 代码 --OrderedDict

```python3
from collections import OrderedDict
class LRUCache(OrderedDict):
    
    def __init__(self, capacity: int):
        self.capacity=capacity

    def get(self, key: int) -> int:
        if key not in self:
            return -1
        self.move_to_end(key)
        return self[key]
    def put(self, key: int, value: int) -> None:
        
        if key in self:
            self.move_to_end(key)
        self[key]=value
        if self.capacity<len(self):
            self.popitem(last=False)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```
### 代码 --双向链表+HASH TABLE
```python3
class Node:#双向链表的节点
    def __init__(self):
        self.value=0
        self.key=0
        self.next=None
        self.prev=None
class LRUCache:
    def __init__(self, capacity: int):
        self.capacity=capacity
        self.cache={}
        self.size=0
        self.head=Node()#哨兵节点
        self.tail=Node()#哨兵节点
        self.head.next=self.tail
        self.tail.prev=self.head
    def _addNode(self,node):#添加到首节点的右边
        node.prev=self.head#建立三个节点间的双向关系
        node.next=self.head.next
        self.head.next.prev=node
        self.head.next=node
    def _removeNode(self,node):#删除节点
        node.prev.next=node.next
        node.next.prev=node.prev
    def _move_to_head(self,node):#先删除节点，再添加节点
        self._removeNode(node)
        self._addNode(node)
    def _pop_tail(self):#移除表尾元素
        temp=self.tail.prev
        self._removeNode(temp)
        return temp
    def get(self, key: int) -> int:
        node=self.cache.get(key,None)#取出key对应的值node
        if not node:
            return -1
        self._move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        node=self.cache.get(key,None)#取出对应键值的节点
        if not node:#节点不存在
            newNode=Node()#build the new node
            newNode.key=key
            newNode.value=value
            self.cache[key]=newNode#store the new_node in HT
            self._addNode(newNode)#add node to linkedlist
            self.size+=1#the size of nodes in linkedlist
            if self.size>self.capacity:#remove the LRU
                tail=self._pop_tail()
                del self.cache[tail.key]
                self.size-=1
        else:#node exit,update the value and move it to head
            self._move_to_head(node)
            node.key=key
            node.value=value



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```