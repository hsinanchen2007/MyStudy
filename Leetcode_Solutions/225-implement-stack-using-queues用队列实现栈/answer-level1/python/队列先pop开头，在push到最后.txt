### 解题思路
push：直接对队列进行push
pop和top：
假设队列的长度是已知的，按队列长度循环，从队列开头pop取出元素，push到最后面，到最后一个时，如果是pop，返回元素，不执行push，如果是top，返回元素，push到队列尾
如果队列长度未知，队列pop后可以先push到另一个队列，但是题目说了队列有size函数，可以知道长度

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        for i in range(len(self.queue)-1):
            temp = self.queue.pop(0)
            self.queue.append(temp)
        return self.queue.pop(0)


    def top(self) -> int:
        """
        Get the top element.
        """
        for i in range(len(self.queue)):
            temp = self.queue.pop(0)
            self.queue.append(temp)
        return temp

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