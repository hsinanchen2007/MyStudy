### 解题思路

用最后4个元素存下容量，以及各个栈的栈顶坐标

### 代码

```python []
class TripleInOne:

    def __init__(self, stackSize: int):
        self.d = [0] * stackSize * 3 + [stackSize * 3, 2, 1, 0]

    def push(self, stackNum: int, value: int) -> None:
        if self.d[~stackNum] < self.d[~3]:
            self.d[self.d[~stackNum]] = value
            self.d[~stackNum] += 3

    def pop(self, stackNum: int) -> int:
        if self.d[~stackNum] >= 3:
            self.d[~stackNum] -= 3
            return self.d[self.d[~stackNum]]
        return -1

    def peek(self, stackNum: int) -> int:
        return self.d[~stackNum] < 3 and -1 or self.d[self.d[~stackNum] - 3]

    def isEmpty(self, stackNum: int) -> bool:
        return self.d[~stackNum] < 3
```