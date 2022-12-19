### 解题思路
使用一个主栈模拟入栈出栈的操作，然而，为了使 $getMin$ 函数实现 $O(1)$ 的时间复杂度，我们可以使用另一个栈来实现。

我们可以将这个栈称为最小栈，每当入栈的数**小于等于**栈顶元素时，随主栈都进行一次 $push$ 操作；

当出栈的数与最小栈的栈顶元素相等时，最小栈也随主栈进行一次 $pop$ 操作。

### 代码

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
        x = self.stack.pop()
        if x == self.minstack[-1]:
            self.minstack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minstack[-1]
```