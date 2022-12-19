### 解题思路
  要注意都是合法的操作！
  queue1作为真正的存储
  queue2作为临时存储

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        只能使用队列的基本操作-- 也就是
        push to back, peek/pop from front, size, 和 is empty
         那就是说 这题 其实也不简单！

         用栈 实现队列
        """
        self.queue1 = []
        self.queue2 = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        queue2  只作为临时的缓存
        """
        self.queue1.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.queue1) != 1:
            self.queue2.append(self.queue1.pop(0))
        # 然后在返回来
        r = self.queue1.pop(0)
        while self.queue2:
            self.queue1.append(self.queue2.pop(0))
        return r

    def top(self) -> int:
        """
        Get the top element.
        得到栈顶
        """
        return self.queue1[-1]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return  len(self.queue1) == 0

```