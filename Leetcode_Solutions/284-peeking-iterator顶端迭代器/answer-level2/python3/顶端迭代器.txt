### 解题思路
本题的关键是，如果没有调用`peek()`，则`next(),hasNext()`与迭代器对应的两个接口用法相同；但是如果调用了`peek()`，则在些之后有两种情况，一是继续调用`peek()`，返回的值不变；如果调用`next()`，返回的值也不变；但之后的调用方法与迭代器原有的两个接口相同；因此这里采用两个变量，分别用来标记之前是否调用过`peek()`及返回的值；如果之后再次调用`next()`，则将标记重置；

本题的核心是用变量`self.flag`表示是否已经用`peek()`返回了元素,为0表示没有，则`next()`和`haxNext()`用迭代器本身相应的两个方法即可；为1表示已经调用过了`peek()`并仍没有调用过`next()`，此时调用`next()`时返回`self.var`，即`peek()`返回的元素，并重置`self.flag`为0；

### 代码

```python3
# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator:
    """
    本题用另外两个变量self.flag来标记是否用了peek()；self.var来保存peek()所返回的值；
    如果在peek()后调用了next()；则将self.flag置0，并返回self.var；
    """
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self.flag = 0
        self.var = None
        

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if self.flag == 0:
            self.flag = 1
            self.var = self.iterator.next()
        
        return self.var
        

    def next(self):
        """
        :rtype: int
        """
        if self.flag == 1:
            self.flag = 0
            return self.var
        else:
            return self.iterator.next()
        

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.flag == 1:
            return True
        return self.iterator.hasNext()        

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
```