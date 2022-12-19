### 解题思路
和另外一题一样

### 代码

```python3
class CQueue:

    def __init__(self):
        self.pushs = []
        self.pops = []

    def appendTail(self, value: int) -> None:
        self.pushs.append(value)

    def deleteHead(self) -> int:
        if len(self.pops)==0:
            for i in range(len(self.pushs)):
                self.pops.append(self.pushs.pop())
        if len(self.pushs)==0 and len(self.pops)==0:
            return -1
        return self.pops.pop()


# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```