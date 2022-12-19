### 解题思路
对于LRU机制一般实现方法是用特殊的栈，栈底保存最久没有使用的key，栈顶保存最近使用的key。
而有序哈希表实际上就是实现了一个查找、栈顶增加、栈底删除以及将某个key直接放到栈顶的这个特殊栈。
注：Python的collections模块中的OrderedDict类就是一个有序哈希表。

### 代码

```python
class Node:
    def __init__(self, key, val):
        self.key = key # 保存key的作用是便于根据节点找到key进而从字典中删除该项
        self.val = val
        self.pre = None
        self.next = None

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.mem = {}
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.pre = self.head

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        # print('get', key, end = '. ')
        if key in self.mem:
            # 把节点从双向链表拆下来
            node = self.mem[key]
            node.pre.next = node.next
            node.next.pre = node.pre
            # 把节点放到链表尾部
            self.tail.pre.next = node
            node.pre = self.tail.pre
            node.next = self.tail
            self.tail.pre = node
            # print(node.val)
            return node.val
        # print(-1)
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        # 将目标节点拆下来
        if key in self.mem or len(self.mem) == self.capacity: # 两个条件的顺序不能反，第一个条件优先
            if key in self.mem:
                temp = self.mem[key] # 删除key节点
            else:
                temp = self.head.next # 删除链表头结点
            temp.pre.next = temp.next
            temp.next.pre = temp.pre
            temp_key = temp.key
            del self.mem[temp_key]
            # print(temp_key, '作废')
        # 将新节点链表尾部
        node = Node(key, value)
        self.mem[key] = node
        self.tail.pre.next = node
        node.pre = self.tail.pre
        node.next = self.tail
        self.tail.pre = node



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```