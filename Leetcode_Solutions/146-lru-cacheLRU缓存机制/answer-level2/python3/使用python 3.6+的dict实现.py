Python3.6+ 实现了[pep-468](https://legacy.python.org/dev/peps/pep-0468/)，普通`dict`的插入顺序也可以得到保留，和`OrderedDict`的区别在于`OrderDict`多了`move_to_end(last)`和`popitem(last)`两个方法。这两个方法也可以用`dict`的方法实现：
```
# 实现 move_to_end(last=True)
d[key] = d.pop(key)

# 实现 popitem(last=False)
head_key = next(iter(d))
d.pop(head_key)
```

使用普通字典的 AC 代码
```
class LRUCache:
    def __init__(self, capacity):
        self._d = dict()
        self.cap = capacity

    def get(self, key: int) -> int:
        if key in self._d:
            self._d[key] = self._d.pop(key)  # move to end
            return self._d[key]
        return -1

    def put(self, key: int, value: int) -> None:
        self._d[key] = value
        self._d[key] = self._d.pop(key)  # move to end

        if len(self._d) > self.cap:
            head_key = next(iter(self._d))
            self._d.pop(head_key)

```
