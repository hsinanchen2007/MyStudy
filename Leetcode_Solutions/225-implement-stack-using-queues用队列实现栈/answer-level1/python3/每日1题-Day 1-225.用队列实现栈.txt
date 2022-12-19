上来第一题就是不熟悉的数据结构……小白选择边抄答案边学习（手动再见）
栈：后进先出，LIFO
队列：先进先出，FIFO
python可以使用单队列list、双队列collections.deque或队列queue.Queue实现。
这里先写（chao）了个list的解法，唯一不能直接return的就是push()，题目限制只能用最基础的几个操作。

代码实现：
```
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.append(x)
        q_len = len(self.q)
        while q_len > 1:
            self.q.append(self.q.pop(0))
            q_len -= 1

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q.pop(0)

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return bool(not self.q)


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```