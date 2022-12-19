1、在pop前或取列表中元素前要注意判断非空；
2、最小栈push时的条件应该是‘<=’，因为重复添加最小值是被允许的，且属于两个不同的元素；

``` Python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = []
        
    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)
        
    def pop(self) -> None:
        if not self.stack:
            return None
        if self.stack.pop() == self.min_stack[-1]:
            self.min_stack.pop()
        
    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        if self.min_stack:
            return self.min_stack[-1]
        else:
            return None
```
