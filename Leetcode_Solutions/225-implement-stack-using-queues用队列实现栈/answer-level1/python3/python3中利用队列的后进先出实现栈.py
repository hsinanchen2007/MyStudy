### 解题思路
python中队列是很重要的一种数据结构，利用队列来实现栈是十分简单的。第一，队列分为先进先出的和后进先出两种队列，鉴于栈的出栈方式那肯定考虑队列的后进先出了。第二，出栈就跟出队形式一样了，入栈也跟入队的形式一样了，就是求栈顶稍微有点麻烦，不过可以借鉴我的方法，找个中间值保存一下。求栈是否为空，则直接调用队列的函数就可以了。

### 代码

```python3
import queue
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.d = queue.LifoQueue()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.d.put(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        rel = self.d.get()
        return rel


    def top(self) -> int:
        """
        Get the top element.
        """
        rel = self.d.get()
        self.d.put(rel)
        return rel


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.d.empty()





# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```