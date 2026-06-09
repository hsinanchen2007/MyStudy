数组输出：

```python []
class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.d = []
        def f(nestedList):
            for nested in nestedList:
                if nested.isInteger():
                    self.d.append(nested.getInteger())
                else:
                    f(nested.getList())
        f(nestedList)
        self.i, self.n = -1, len(self.d) - 1

    def next(self) -> int:
        self.i += 1
        return self.d[self.i]
    
    def hasNext(self) -> bool:
        return self.i < self.n

```

迭代器输出：

```python []
class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        def f(nestedList):
            for nested in nestedList:
                if nested.isInteger():
                    yield nested.getInteger()
                else:
                    yield from f(nested.getList())
        self.iter = f(nestedList)

    def next(self) -> int:
        return self.nxt
    
    def hasNext(self) -> bool:
        try:
            self.nxt = next(self.iter)
            return True
        except:
            return False
```


![image.png](https://pic.leetcode-cn.com/b88e6ed4818b887b4afe95cee51674eeaa3813be85b3f082694994e1c2ae783d-image.png)

