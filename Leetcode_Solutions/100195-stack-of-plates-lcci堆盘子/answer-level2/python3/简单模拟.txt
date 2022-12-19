- 简单模拟, pop可以直接调用popAt(len-1)
- **注意如果cap为0则不能push**
- **注意如果popAt某个index导致该index的stack为空的话, 需要将后面的stack往前移动**
    - (*题目描述示例2和实际测试用例结果不一样???*)
```python
class StackOfPlates:
    def __init__(self, cap: int):
        self.cap = cap
        self.stacks = []

    def push(self, val: int) -> None:
        if self.cap == 0:
            return
        if not self.stacks or len(self.stacks[-1]) == self.cap:
            self.stacks.append([val])
        else:
            self.stacks[-1].append(val)

    def pop(self) -> int:
        return self.popAt(len(self.stacks) - 1)

    def popAt(self, index: int) -> int:
        if not self.stacks or index >= len(
                self.stacks) or not self.stacks[index]:
            return -1
        res = self.stacks[index].pop()
        if not self.stacks[index]:
            self.stacks = self.stacks[0:index] + self.stacks[index + 1:]
        return res
```
