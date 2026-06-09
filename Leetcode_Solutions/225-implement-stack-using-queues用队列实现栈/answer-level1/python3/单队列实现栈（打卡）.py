### 解题思路
首先要明确的是，栈的结构是“先进后出（后进先出）”，而队列的结构是“先进先出”，举例来说同样是内容为[1,2,3,4,5]，即进栈或者进队列的顺序为1,2,3,4,5。由于先进后出的结构，则出栈时的顺序为，5,4,3,2,1。而对于队列来说，则出队列的顺序为1,2,3,4,5。
看完了必要的基础知识，针对队列实现栈结构这个问题。最简单直观的思路，能不能直接在队列的规则基础上将数据存储为栈的结构。这句话可能有点不好理解。举个例子来说，对于[1,2,3,4,5]这样的数据，出栈的顺序为，5，4,3,2,1  那么如果我们要用出队列的方式实现5,4,3,2,1的输出顺序应该怎么做？

答案是很直观的，那就是在队列中将数据，倒过来存储，即5,4,3,2,1的存储方式。这样的话每次出队列的元素就和出栈的元素达到一致。

那么push操作的实现就很容易理解了，每次利用put操作将数据加入队列后，根据队列“先进先出”的特性，把本次操作前入队的元素全部取出来重新入队，这样就可以保证，每次put的末尾元素将优先出队，即“后进先出”。

其他操作就比较容易理解了。


### 代码

```
from queue import Queue
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue =  Queue()


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue.put(x)
        for i in range(self.queue.qsize()-1):
            self.queue.put(self.queue.get())


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        x = self.queue.get()
        return x


    def top(self) -> int:
        """
        Get the top element.
        """
        t = self.queue.get()
        self.push(t)
        return t


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if not self.queue.qsize():
            return True
        return False
```

