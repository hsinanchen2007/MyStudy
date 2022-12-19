```
class CQueue:

    def __init__(self):
        self.in_ = []
        self.out = []
        

    def appendTail(self, value: int) -> None:
        self.in_.append(value)
        

    def deleteHead(self) -> int:
        if not self.out:
            while self.in_:
                self.out.append(self.in_.pop())
        if not self.out: return -1 
        return self.out.pop()
```
