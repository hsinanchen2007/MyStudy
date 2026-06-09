本题的迭代器应该如下理解,只有hasNext()函数返回True,才会继续调用next()方法.这是类似Java中迭代器的做法
而在Python中采用的原则是It's easier to ask forgive than it is to get permission.没有hasNext()函数,通过不断调用next()方法,直到触发StopIteration异常停止为止.
```python
class NestedIterator:
    def __init__(self, nestedList):
        def build_generator(nestedList):
            for x in nestedList:
                if x.isInteger():
                    yield x.getInteger()
                else:
                    yield from build_generator(x.getList())
        self.elements = build_generator(nestedList)

    def next(self) -> int:
        return self.v

    def hasNext(self) -> bool:
        try:
            self.v = next(self.elements)
            return True
        except StopIteration:
            return False
```
