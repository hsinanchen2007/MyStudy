思路的核心还是不论有多少最小值都压入栈里，这样pop其中一个最小值，目前的最小值也不变
```python
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = list()
        self.minimal = list()
        

    def push(self, x: int) -> None:
        self.stack.append(x)
        # 关键在于后面的判断取等号，这样不论多少个最小值都会被压入栈里
        if not self.minimal or x <= self.minimal[-1]:
            self.minimal.append(x)

    def pop(self) -> None:
        current = self.stack.pop()
        if current == self.minimal[-1]:
            self.minimal.pop()

    def top(self) -> int:
        return self.stack[-1]

    def min(self) -> int:
        return self.minimal[-1]
```
