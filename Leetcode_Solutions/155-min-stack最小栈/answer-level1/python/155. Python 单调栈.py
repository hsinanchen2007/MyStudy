### 解题思路
按照题意叙述实际上就是维护一个普通的栈和一个单调栈，单调栈用于保存普通栈中的最小值。

### 代码

```python
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = []


    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.stack.append(x)
        if len(self.min_stack) == 0 or x <= self.min_stack[-1]:
            self.min_stack.append(x)


    def pop(self):
        """
        :rtype: None
        """
        x = self.stack[-1]
        del self.stack[-1]
        if x == self.min_stack[-1]:
            del self.min_stack[-1]


    def top(self):
        """
        :rtype: int
        """
        print(self.stack[-1])
        return self.stack[-1]


    def getMin(self):
        """
        :rtype: int
        """
        print(self.min_stack[-1])
        return self.min_stack[-1]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```