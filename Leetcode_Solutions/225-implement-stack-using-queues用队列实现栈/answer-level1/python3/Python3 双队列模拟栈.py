### 解题思路
每次pop()和top()之后, q1, q2交换一下, 始终保持q1指向有元素的队列, 
这样每次插入的时候就不需要判断该往哪个队列中插入新元素

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        from collections import deque
        self.q1, self.q2 = deque([]), deque([])

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        # q1元素 倒到 q2
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        # 此时元素都到了q2, 下次在出栈, 就要从q2倒到q1, 
        # 这里交换q1, q, 统一, 使得每次都是q1倒到q2
        self.q1, self.q2 = self.q2, self.q1
        return self.q2.popleft()
        

    def top(self) -> int:
        """
        Get the top element.
        """
        # 同理, q1倒到q2, 但这个方法不需要删除元素, 所以访问完,还要倒干净
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        # 先记下栈顶元素
        res = self.q1[-1]
        # 倒干净, 在交换q1, q2, 始终保证q1指向有元素的队列
        self.q2.append(self.q1.popleft())
        self.q1, self.q2 = self.q2, self.q1
        return res
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.q1) + len(self.q2) == 0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```