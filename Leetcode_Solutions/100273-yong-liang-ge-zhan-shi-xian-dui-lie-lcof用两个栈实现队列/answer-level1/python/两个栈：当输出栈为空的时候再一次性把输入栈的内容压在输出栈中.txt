### 解题思路
当输出栈为空的时候再一次性把输入栈的内容压在输出栈中
### 代码

```python3
class CQueue:

    def __init__(self):
        self.A = []
        self.B = []

    def appendTail(self, value: int) -> None:
        self.A.append(value)

    def deleteHead(self) -> int:
        if len(self.A) == 0 and len(self.B) == 0:
            return -1
        if self.B:
            ans = self.B.pop()
            return ans
        else:
            for i in range(len(self.A)):
                self.B.append(self.A.pop())
            return self.B.pop() 


# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```