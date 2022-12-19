### 解题思路
此处撰写解题思路

### 代码

```python3
class CQueue:

    def __init__(self):
        self.A = []
        self.B = []

    def appendTail(self, value: int) -> None:
        self.B.append(value)
    def deleteHead(self) -> int:
        #每个元素进入b一次，进入a一次
        if not self.A:
            while self.B:
                self.A.append(self.B.pop())
            
        if not self.A:
            return -1
        return self.A.pop()



# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```