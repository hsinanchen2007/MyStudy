### 解题思路
此处撰写解题思路

### 代码

```python3
class CQueue:

    def __init__(self):
        self.q1 = []
        self.q2 = []

    def appendTail(self, value: int) -> None:
        self.q1.append(value)

    def deleteHead(self) -> int:
        if not self.q1: return -1
        while self.q1:
            self.q2.append(self.q1.pop())
        res = self.q2.pop()
        while self.q2:
            self.q1.append(self.q2.pop())
        return res
        


# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```