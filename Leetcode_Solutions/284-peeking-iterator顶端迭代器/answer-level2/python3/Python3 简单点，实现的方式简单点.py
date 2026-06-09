把传入的迭代器内容存到列表中
用个数字记录当前的index
peek只返回列表\[index\]
next就把index+1后返回列表\[index - 1\]
进阶要求在这个解法面前真是太弟弟了（逃
```python
class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """

        self.container = []
        while iterator.hasNext():
            self.container.append(iterator.next())
        self.cur = 0
        

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        return self.container[self.cur]
        

    def next(self):
        """
        :rtype: int
        """
        self.cur += 1
        return self.container[self.cur - 1]
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return not self.cur == len(self.container)
```