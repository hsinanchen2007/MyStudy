常规类型：

```python []
class PeekingIterator:
    def __init__(self, iterator):
        self.iterator = iterator
        self.cache = None

    def top(self):
        if self.cache is None and self.iterator.hasNext():
            self.cache = self.iterator.next()
        return self.cache

    def peek(self):
        return self.top()

    def next(self):
        if self.top() is not None:
            self.cache, res = None, self.cache
        return res

    def hasNext(self):
        return bool(self.top())
```

支持自定类型：

```python []
class PeekingIterator:
    def __init__(self, iterator):
        self.iterator = iterator
        self.cache = []

    def top(self):
        not self.cache and self.iterator.hasNext() and self.cache.append(self.iterator.next())

    def peek(self):
        return self.top() or self.cache[0]

    def next(self):
        return self.top() or self.cache.pop()

    def hasNext(self):
        return self.top() or bool(self.cache)
```

![image.png](https://pic.leetcode-cn.com/e812665d732a7e15a3677a2e1637d440e48a305831b97c99a6789f74ba2713f6-image.png)
