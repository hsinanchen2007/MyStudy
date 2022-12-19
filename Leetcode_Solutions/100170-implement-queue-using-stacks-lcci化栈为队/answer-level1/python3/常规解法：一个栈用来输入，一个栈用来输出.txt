### 解题思路
+ push的时候，首先要保证输入栈为空，不为空则先将输入栈的元素“倒入”输出栈，然后再进行入栈操作，并且size+1
+ pop的时候，首先要保证两个栈不为空，若为就那个则返回-1，然后判断输出栈是否为空，不为空则执行pop操作size-1
+ peek的时候，基本操作和pop一样，区别就是不用讲元素出栈，只需要返回输出栈的栈顶元素即可
+ empty：只需要判断size即可（return True if self.size==0 else False）


### 代码

```python3
"""
实现一个MyQueue类，该类用两个栈来实现一个队列。
"""


class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 0
        self.stack1 = []
        self.stack2 = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        if self.stack1:
            # 如果栈1不为空，则把栈1中的元素全部转移到栈2
            length = len(self.stack1)
            for i in range(length):
                item = self.stack1.pop()
                self.stack2.append(item)
        self.stack1.append(x)
        self.size += 1

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if not self.stack1 and not self.stack2:
            return -1

        if not self.stack2:
            length = len(self.stack1)
            for _ in range(length):
                item = self.stack1.pop()
                self.stack2.append(item)
        x = self.stack2[0]
        self.stack2 = self.stack2[1:]
        self.size-=1
        return x

    def peek(self) -> int:
        """
        Get the front element.
        """
        if not self.stack1 and not self.stack2:
            return -1

        if not self.stack2:
            length = len(self.stack1)
            for _ in range(length):
                item = self.stack1.pop()
                self.stack2.append(item)

        return self.stack2[0]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return True if self.size==0 else False

```