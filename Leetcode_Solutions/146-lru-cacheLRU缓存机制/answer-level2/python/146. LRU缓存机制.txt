### 解题思路
LRU（最久未使用淘汰算法）是操作系统内存管理中页面比较有名的淘汰算法。下面是官方提供的第一份代码，用到了有序字典，实现了查找与置换O(1)的时间复杂度。其中要注意的一点是，get操作对于已存在字典中的key来说，会让其重新排序FIFO的顺序，为置换做准备，但若不在字典中，返回的是-1，并不是去put改值；置换操作只发生在put操作，且当前数量>capacity。

### 代码

```python3
from collections import OrderedDict

class LRUCache(OrderedDict):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self:
            return - 1

        self.move_to_end(key)
        return self[key]

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self:
            self.move_to_end(key)
        self[key] = value
        if len(self) > self.capacity:
            self.popitem(last=False)
```