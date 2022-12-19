class NestedIterator(object):
    
    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.stack = []

        def flatten(objs):
            for obj in objs:
                if obj.isInteger():
                    self.stack.append(obj.getInteger())
                else:
                    flatten(obj.getList())

        flatten(nestedList)

    def next(self):
        """
        :rtype: int
        """
        return self.stack.pop(0)

    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.stack)>0