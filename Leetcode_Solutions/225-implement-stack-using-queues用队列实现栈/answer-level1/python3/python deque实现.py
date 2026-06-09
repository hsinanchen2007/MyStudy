
```
from collections import deque
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = deque()
        self.t = None


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.append(x)
        self.t = x



    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        tmp = self.t
        self.t = None
        while True:
            tt = self.q.popleft()
            if tt == tmp:
                break
            self.q.append(tt)
            self.t = tt 

        
        return tmp


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.t


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if self.q:
            return False
        else:
            return True



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```
