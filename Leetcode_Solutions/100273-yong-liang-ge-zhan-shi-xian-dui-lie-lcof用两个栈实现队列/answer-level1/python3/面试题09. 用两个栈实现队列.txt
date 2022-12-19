### 解题思路
- 进队列，直接使用其中一个stack1的append函数，出队列的时候，将stack1中所有的值都加如到stack2中，然后pop出stack2中的一个值。
- 下一次出队列时，判断stack2中是否有值，有就直接，pop一个值，没有就再一次将所有stack1中的值加入到stack2中
### 代码

```python3
class CQueue:

    def __init__(self):
        self.stack1 =[]
        self.stack2= []

    def appendTail(self, value: int) -> None:
        self.stack1.append(value)


    def deleteHead(self) -> int:
        if self.stack2:
            return self.stack2.pop()
        elif self.stack1:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
            return self.stack2.pop()
        else:
            return -1
# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```