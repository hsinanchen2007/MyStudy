![image.png](https://pic.leetcode-cn.com/8adf355daf3b87a4f435f80b3bf7f5aad4d5b9d5c40bc3a0f836288f785428fd-image.png)

`del` 关键字似乎比 `pop()` 更快点。

```python []
class MyLinkedList:

    def __init__(self):
        self.h = []

    def get(self, index: int) -> int:
        return self.h[index] if 0 <= index < len(self.h) else -1
        
    def addAtHead(self, val: int) -> None:
        self.h.insert(0, val)

    def addAtTail(self, val: int) -> None:
        self.h.append(val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index <= len(self.h): self.h.insert(index if index >= 0 else 0, val)

    def deleteAtIndex(self, index: int) -> None:
        if 0 <= index < len(self.h): del self.h[index]
```
