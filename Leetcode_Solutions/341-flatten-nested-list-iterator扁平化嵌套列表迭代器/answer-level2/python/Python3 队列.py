`执行用时: 92 ms`
`内存消耗: 17.4 MB`

使用队列，将嵌套列表内的所有整数都入队，取下一个时出队。入队时，若为整数，则直接入队，若为嵌套列表，则递归调用入队函数。

```py
class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.queue = []
        def queue_push(n_l):
            for item in n_l:
                if item.isInteger():
                    self.queue.append(item.getInteger())
                else:
                    queue_push(item.getList())
        queue_push(nestedList)

    def next(self):
        """
        :rtype: int
        """
        return self.queue.pop(0)

    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.queue) > 0
```