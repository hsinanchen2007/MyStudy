

### 代码

```python
class CQueue:

    def __init__(self):
        self.appendstack = []
        self.deletestack = []

    def appendTail(self, value: int) -> None:
        self.appendstack.append(value)

    def deleteHead(self) -> int:
        if self.deletestack:
            return self.deletestack.pop()
        else:
            while self.appendstack:
                self.deletestack.append(self.appendstack.pop())
            return self.deletestack.pop() if self.deletestack else -1

```