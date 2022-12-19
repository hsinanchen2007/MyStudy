### 解题思路
时间复杂度：对于 put 和 get 操作复杂度是 O(1)O(1)，因为有序字典中的所有操作：get/in/set/move_to_end/popitem（get/containsKey/put/remove）都可以在常数时间内完成。
空间复杂度：O(capacity)O(capacity)，因为空间只用于有序字典存储最多 capacity + 1 个元素。


### 代码

```python3
from collections import OrderedDict
class LRUCache(OrderedDict):

    def __init__(self, capacity):
        self.od, self.cap = collections.OrderedDict(), capacity

    def get(self, key):
        if key not in self.od: return -1
        self.od.move_to_end(key)
        return self.od[key]

    def put(self, key, value):
        if key in self.od: del self.od[key]
        elif len(self.od) == self.cap: self.od.popitem(False)
        self.od[key] = value



# LRUCache 对象会以如下语句构造和调用:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

```