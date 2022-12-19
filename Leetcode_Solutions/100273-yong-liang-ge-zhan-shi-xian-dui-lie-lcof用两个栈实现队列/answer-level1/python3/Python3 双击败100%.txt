### 解题思路
对list进行操作

### 代码

```python3
class CQueue:

    def __init__(self):
        self.dp=[]

    def appendTail(self, value: int) -> None:
        self.dp.append(value)

    def deleteHead(self) -> int:
        if len(self.dp)==0:
            return -1
        else:
            return self.dp.pop(0)



# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```