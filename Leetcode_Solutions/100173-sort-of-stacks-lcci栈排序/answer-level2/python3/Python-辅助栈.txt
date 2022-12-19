```
class SortedStack:

    def __init__(self):
        self.stk = []


    def push(self, val: int) -> None:
        tmp_stk = []
        while self.stk and self.stk[-1] < val:
            tmp_stk.append(self.stk.pop())
        self.stk.append(val)
        while tmp_stk:
            self.stk.append(tmp_stk.pop())


    def pop(self) -> None:
        if self.isEmpty():
            return
        self.stk.pop()

    def peek(self) -> int:
        if self.isEmpty():
            return -1
        return self.stk[-1]


    def isEmpty(self) -> bool:
        return len(self.stk) == 0
```
