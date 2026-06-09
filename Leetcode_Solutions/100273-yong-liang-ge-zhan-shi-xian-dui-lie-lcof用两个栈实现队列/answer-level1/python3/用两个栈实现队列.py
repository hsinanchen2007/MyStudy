### 解题思路
将输入数据放到栈A，依次取出栈A数据放到栈B，此刻栈B是栈A的逆序，再弹出栈B的数据即是队列的顺序。

### 代码

```python3
class CQueue:

    def __init__(self):
        self.stackA=[]
        self.stackB=[]

    def appendTail(self, value: int) -> None:
        self.stackA.append(value)

    def deleteHead(self) -> int:
        if not self.stackB:
            while self.stackA:
                self.stackB.append(self.stackA.pop())

        if not self.stackB:
            return -1
        else:
            return self.stackB.pop()


# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```