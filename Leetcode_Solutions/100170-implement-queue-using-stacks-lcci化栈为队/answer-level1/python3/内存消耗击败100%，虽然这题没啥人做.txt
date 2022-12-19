### 解题思路
分为输入输出两个栈，输入栈正常push
pop时若输出栈为空，则将输入栈自顶向下逐个push进输出栈，否则正常pop
peek时按题目要求只用常规栈操作，不知道列表的[-1]行不行，先用pop顶一下

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.pushs = []
        self.pops = []


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.pushs.append(x)


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if len(self.pops)==0:
            for i in range(len(self.pushs)):
                self.pops.append(self.pushs.pop())
        return self.pops.pop()


    def peek(self) -> int:
        """
        Get the front element.
        """
        if len(self.pops)==0:
            for i in range(len(self.pushs)):
                self.pops.append(self.pushs.pop())
        temp = self.pops.pop()
        self.pops.append(temp)
        return temp


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        if len(self.pushs)==0 and len(self.pops)==0:
            return True
        else:
            return False



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```