### 解题思路

设置一颗最辅助的单调递减最小栈，如果主栈弹出元素与最小栈顶一致，则可以同时弹出最小栈的栈顶元素

```python []
class MinStack:

    def __init__(self):
        self.stack = []
        self.minstack = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.minstack or x <= self.minstack[-1]:
            self.minstack.append(x)

    def pop(self) -> None:
        if self.stack.pop() == self.minstack[-1]:
            self.minstack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def min(self) -> int:
        return self.minstack[-1]
```