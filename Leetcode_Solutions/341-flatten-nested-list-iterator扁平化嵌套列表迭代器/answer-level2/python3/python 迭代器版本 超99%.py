```python
class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        def build_generator(nestedList):
            for i in nestedList:
                if i.isInteger():
                    yield i.getInteger()
                else:
                    i = i.getList()
                    for j in build_generator(i):
                        yield j
        self.g = build_generator(nestedList)

    def next(self):
        """
        :rtype: int
        """
        #print(self.v)
        return self.v

    def hasNext(self):
        """
        :rtype: bool
        """
        try:
            self.v = next(self.g)
        #print(self.v)
            return True
        except:
            return False
```