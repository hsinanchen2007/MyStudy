### 解题思路
每次写这道题都想到爱的魔力转圈圈，其实就是把队首的元素依次放到队尾，然后弹出末尾的元素，循环的次数就是长度-1

### 代码

```
from collections import deque
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data1 = deque()
        self.data2 = deque()


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.data1.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.data1)>1:
            self.data2.append(self.data1.popleft())
        tmp = self.data1.popleft()
        self.data1,self.data2 = self.data2,self.data1
        return tmp



    def top(self) -> int:
        """
        Get the top element.
        """
        while len(self.data1)>1:
            self.data2.append(self.data1.popleft())
        tmp = self.data1.popleft()
        self.data2.append(tmp)
        self.data1,self.data2 = self.data2,self.data1
        return tmp

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.data1)==0


```
