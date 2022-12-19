使用dict的时候key是无序的，OrderedDict可以保持key的顺序（按照加入字典的顺序）

除了keys()、items()、values()这些方法之外，还有两个特殊的方法：

#### popitem(last=True)

默认pop字典最后一个键值对，可以用 last=False 来pop字典第一个键值对

```
>>> import collections
>>> d1 = collections.OrderedDict()
>>> d1[1]=1
>>> d1[2]=2
>>> d1[3]=3
>>> d1.popitem()
(3, 3)
>>> d1.popitem(last=False)
(1, 1)
```

#### move_to_end(key, last=True)

将某个key移到字典尾部

```
>>> d1
OrderedDict([(3, 3), (1, 1)])
>>> d1.move_to_end(3)
>>> d1
OrderedDict([(1, 1), (3, 3)])
```

### 解法

```python
class LRUCache:

    def __init__(self, capacity: int):
        self.lookup = collections.OrderedDict()
        self.cap = capacity
        self.count = 0

    def get(self, key: int) -> int:
        value = self.lookup.get(key, -1)
        if value != -1:
            # 字典尾部为最近访问过的数据
            self.lookup.move_to_end(key)
        return value

    def put(self, key: int, value: int) -> None:
        # 先判断是否在缓存中
        if key in self.lookup:
            self.lookup[key] = value
            self.lookup.move_to_end(key)
        else:
            # 缓存已满
            if self.count >= self.cap:
                self.lookup.popitem(last=False)
            else:
                self.count += 1
            self.lookup[key] = value
```