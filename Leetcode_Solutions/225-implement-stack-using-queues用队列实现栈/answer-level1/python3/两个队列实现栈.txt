### 解题思路
使用两个队列，一个队列用于存放有序的元素，另一个队列用于获取队尾元素的缓冲。
push操作：直接找到不为空的队列，元素进队列，时间为O(1),
pop操作：找到非空的队列，将除最后一个的元素存在另一个队列里，删除最后一个元素，时间复杂度为O(n)

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        队列用list实现，入队列是append(), 出队列pop(0)
        """
        self.q1 = []
        self.q2 = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        if self.q1:
            self.q1.append(x)
        else:
            self.q2.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if self.q1:
            for i in range(len(self.q1)-1):
                tmp = self.q1.pop(0)
                self.q2.append(tmp)
            res = self.q1.pop(0)
            return res
        else:
            for i in range(len(self.q2)-1):
                tmp = self.q2.pop(0)
                self.q1.append(tmp)
            res = self.q2.pop(0)
            return res

    def top(self) -> int:
        """
        Get the top element.
        """
        if self.q1:
            for i in range(len(self.q1)-1):
                tmp = self.q1.pop(0)
                self.q2.append(tmp)
            res = self.q1.pop(0)
            self.q2.append(res)
            return res
        else:
            for i in range(len(self.q2)-1):
                tmp = self.q2.pop(0)
                self.q1.append(tmp)
            res = self.q2.pop(0)
            self.q1.append(res)
            return res

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not(self.q1 or self.q2)



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```