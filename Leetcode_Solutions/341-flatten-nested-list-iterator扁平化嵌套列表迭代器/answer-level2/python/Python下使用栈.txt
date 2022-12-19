编写next函数的时候需要特别注意，先取出栈顶值，再调用迭代函数。否则，在遇到空的嵌套列表时就会出错。
例如`[[1],[]]`，flatten保证`1`位于栈顶；取出1；
此时栈内存储了一个空列表，hasNext会返回True，因此进行第二次调用；flatten后栈为空，pop出错。

```
class NestedIterator(object):
    
    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.stack = nestedList[::-1] # 逆序初始化栈
        self.flattenStack() # 调用一次迭代，保证栈顶元素为Integer
        
        
    def flattenStack(self):
        while (self.stack) and (not self.stack[-1].isInteger()): # 先保证栈非空，再迭代栈顶直至栈顶元素为Integer
            nestedList = self.stack.pop()
            self.stack.extend(nestedList.getList()[::-1]) # nestedList -> list -> reverse

    def next(self):
        """
        :rtype: int
        """
        val = self.stack.pop() # 取出栈顶元素
        val = val.getInteger() # 转为int对象
        self.flattenStack() # 再次调用迭代函数
        return val

    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.stack) != 0
```
