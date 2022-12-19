### 解题思路
用两个队列来模拟栈，令为队列1，队列2，我认为最关键的部分在于pop的时候。
push：队列1进元素即可
pop：把队列1先进的元素全部出队，直到留下最后一个元素，且队列1全部出队的元素按顺序进队列2。到现在为止，队列1留下的那个元素就是栈顶，弹出即可。弹出后队列1为空了，把队列2的元素再依次出队，再依次进队列1。也就是说，整个过程中，队列1一直是主要队列，队列2是辅助用的，用来倒腾元素。


### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1 = list()
        self.queue2 = list()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue1.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.pop(0))
        pop_value = self.queue1.pop()
        while len(self.queue2) != 0:
            self.queue1.append(self.queue2.pop(0))
        return pop_value

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.queue1[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.queue1) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```