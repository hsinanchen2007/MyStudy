### 解题思路
学会用
from collections import OrderedDict
学会用
move_to_end
### 代码

```python3
from collections import OrderedDict
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.orderdict = OrderedDict()
    
    def get(self, key: int) -> int:
        if key not in self.orderdict:
            return -1
        else:
            self.orderdict.move_to_end(key)
            return self.orderdict[key]
    def put(self, key: int, value: int) -> None:
        if key in self.orderdict:
            self.orderdict[key] = value
            self.orderdict.move_to_end(key)
        else:
            if(len(self.orderdict)>=self.capacity):
                self.orderdict.popitem(last=False)
            self.orderdict[key] = value





# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```