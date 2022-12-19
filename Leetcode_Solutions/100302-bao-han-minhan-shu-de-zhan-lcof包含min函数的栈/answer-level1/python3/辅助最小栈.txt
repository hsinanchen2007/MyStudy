```python
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self._min_stack = []
        self._min = float('inf')


    def push(self, x: int) -> None:
        self.stack.append(x)
        self._min = min(self._min, x)
        self._min_stack.append(self._min)

    def pop(self) -> None:
        if not self.stack: return
        self.stack.pop()
        self._min_stack.pop()
        if not self._min_stack:
            self._min = float('inf')
        else:
            self._min = self._min_stack[-1]


    def top(self) -> int:
        if not self.stack: return 
        return self.stack[-1]


    def min(self) -> int:
        if not self._min_stack: return
        return self._min_stack[-1]
```