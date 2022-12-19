
### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue=[]
        self.helper=[]


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.queue)>1:
            self.helper.append(self.queue.pop(0))
        res=self.queue.pop()
        self.helper,self.queue=self.queue,self.helper
        return res


    def top(self) -> int:
        """
        Get the top element.
        """
        while len(self.queue)>1:
            self.helper.append(self.queue.pop(0))
        res=self.queue.pop()
        self.helper.append(res)
        self.helper,self.queue=self.queue,self.helper
        return res

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.queue)==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```