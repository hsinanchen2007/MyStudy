### 解题思路
剑指offer中————栈和队列
1、用两个栈模拟队列相对较简单；
2、用两个队列模拟栈，主要是pop和peek操作，每次pop或peek都需要将所有元素转移到另一个队列，然后返回当前队列的最后一个元素。

### 代码

```python3
class MyStack:
    
    def __init__(self):
        from queue import Queue
        """
        Initialize your data structure here.
        """
        self.que_1 = Queue()
        self.que_2 = Queue()


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        if not self.que_1.empty():
            self.que_1.put(x)
        else:
            self.que_2.put(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if not self.que_1.empty():
            while self.que_1.qsize() > 1:
                self.que_2.put(self.que_1.get())
            return self.que_1.get()
        elif not self.que_2.empty():
            while self.que_2.qsize() > 1:
                self.que_1.put(self.que_2.get())
            return self.que_2.get()
        else:
            return None


    def top(self) -> int:
        """
        Get the top element.
        """
        if not self.que_1.empty():
            while self.que_1.qsize() > 1:
                self.que_2.put(self.que_1.get())
            item = self.que_1.get()
            self.que_2.put(item)
            return item
        elif not self.que_2.empty():
            while self.que_2.qsize() > 1:
                self.que_1.put(self.que_2.get())
            item = self.que_2.get()
            self.que_1.put(item)
            return item
        else:
            return None

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.que_1.empty() and self.que_2.empty()



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```