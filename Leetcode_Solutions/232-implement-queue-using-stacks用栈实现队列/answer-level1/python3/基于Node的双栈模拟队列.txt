### 解题思路
首先定义Node类，在此基础上定义Stack并实现增删查；基于Stack实现队列

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.in_stack = Stack()
        self.out_stack = Stack()


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.in_stack.push(x)
        return


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.out_stack.head == None:
            while self.in_stack.head:
                self.out_stack.push(self.in_stack.pop())
        return(self.out_stack.pop())

    def peek(self) -> int:
        """
        Get the front element.
        """
        if self.out_stack.head == None:
            while self.in_stack.head:
                self.out_stack.push(self.in_stack.pop())
        return(self.out_stack.head.data)

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return self.out_stack.head == None and self.in_stack.head == None

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self, head = None):
        self.head = head
        self.count = 0

    def push(self, data):
        node = Node(data)
        if self.head == None:
            self.head = node
        else:
            node.next = self.head
            self.head = node
        self.count += 1
        return

    def pop(self):
        if self.count == 0:
            raise ValueError('length must be greater than zero')
        
        temp = self.head
        self.head = self.head.next
        self.count -= 1
        return temp.data

    def peek(self):
        if self.count == 0:
            raise ValueError('length must be greater than zero')
        return self.head.data

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```