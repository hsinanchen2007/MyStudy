### 解题思路
数据栈与辅助栈同步

### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.helper = []

    def push(self, x: int) -> None:
        self.data.append(x)
        if len(self.helper) == 0 or x <= self.helper[-1]:
            self.helper.append(x)
        else:
            self.helper.append(self.helper[-1])

    def pop(self) -> None:
        self.data.pop()
        self.helper.pop()

    def top(self) -> int:
        return self.data[-1]

    def min(self) -> int:
        return self.helper[-1]

```