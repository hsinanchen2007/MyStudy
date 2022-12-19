### 解题思路
    push(x) -- 元素 x 入栈
    pop() -- 移除栈顶元素
    top() -- 获取栈顶元素
    empty() -- 返回栈是否为空
使用List实现一个队列类MyQueue。
实现栈类MyStack。
push(x)方法：同队列的push方法，直接调用MyQueue的push。
pop()方法：队列pop方法为抛出队首元素，循环栈长度-1次，调用队列的pop方法和push方法重新回到栈，此时栈底元素为原栈顶元素，调用pop抛出原栈顶元素。
top()方法：队列peek方法为获取队首元素，循环栈长度-1次，调用队列的pop方法和push方法重新压回到栈，此时栈底元素为原栈顶元素，调用peek方法获取原栈顶元素赋值给变量x，并再次调用pop方法和push方法将其压回到栈顶，保证原栈无变化，return x。

### 代码

```python
class MyQueue:
    def __init__(self):
        self.queue = []
        
    def push(self, x):
        return self.queue.append(x)
        
    def pop(self):
        return self.queue.pop(0)
    
    def peek(self):
        return self.queue[0]
    
    def size(self):
        return len(self.queue)
        
    def empty(self):
        return self.queue == []


class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = MyQueue()


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.queue.push(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        for _ in range(self.queue.size() - 1):
            self.queue.push(self.queue.pop())
        return self.queue.pop()

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        for i in range(self.queue.size() - 1):
            self.queue.push(self.queue.pop())
        x = self.queue.peek()
        self.queue.push(self.queue.pop())
        return x

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self.queue.empty()


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```