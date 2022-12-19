
### 代码

```python3
class MyStack:

    def __init__(self):
        self.prior_q = []
        self.aux_q = []
        self.top_var = 0


    def push(self, x: int) -> None:
        self.prior_q.append(x)
        self.top_var = x


    def pop(self) -> int:
        while self.prior_q[0] != self.top_var:
            self.aux_q.append(self.prior_q.pop(0))
        temp = self.prior_q.pop(0)
        while self.aux_q:
            if len(self.aux_q) == 1:
                self.top_var = self.aux_q[0]
            self.prior_q.append(self.aux_q.pop(0))
        return temp

    def top(self) -> int:
        return self.top_var


    def empty(self) -> bool:
        return len(self.prior_q) == 0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```