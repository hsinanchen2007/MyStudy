### 解题思路
学习了python的queue和deque类。关键就是栈LIFO。
queue是单向队列，用于实现多线程时，同步读写的一个类。但是python有GIL，不太知道这个类意义何在。它的对象是不可迭代的，所以不支持索引。
deque是双向队列。它的对象可以迭代，可以索引，感觉和list没差。另外一点就是pop，append都是在队列右端操作。与之相对的是popleft和popright。

### 代码

```python3
class MyStack:
    

    def __init__(self):
        """
        Initialize your data structure here.
        """
        from collections import deque
        self.__q = deque()


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.__q.append(x)
        return

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.__q.pop()

    def top(self) -> int:
        """
        Get the top element.
        """
        # ret = self.__q.popleft()
        # self.__q.append(ret)
        return self.__q[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return True if len(self.__q) == 0 else False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```