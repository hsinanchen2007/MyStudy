### 解题思路
栈的特点：先进后出
队列的特点：先进先出

先进后出+先进后出=先进先出
两个栈刚好可以实现队列


### 代码

```python3
class CQueue:

    def __init__(self):
        self.A,self.B=[],[]


    def appendTail(self, value: int) -> None:
        self.A.append(value)

    


    def deleteHead(self) -> int:
        if len(self.B)==0:
            while self.A:
                self.B.append(self.A.pop())
        if len(self.B)==0:
            return -1
        return self.B.pop()



# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```