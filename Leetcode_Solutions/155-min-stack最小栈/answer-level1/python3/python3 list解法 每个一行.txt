### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.jian=[]

    def push(self, x: int) -> None:
        self.jian.append(x)

    def pop(self) -> None:
        self.jian.pop()

    def top(self) -> int:
        return self.jian[-1]

    def getMin(self) -> int:
        return sorted(self.jian)[0]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```