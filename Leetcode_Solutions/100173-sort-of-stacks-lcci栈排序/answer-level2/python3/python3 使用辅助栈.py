### 解题思路
设置辅助栈，若数据栈栈顶元素小于当前push元素，则把数据栈栈顶元素弹出到辅助栈，若数据栈栈顶元素大于当前push元素，则把push元素 压入辅助栈，之后把数据栈剩下元素全部压入辅助站。最后，把辅助栈元素全部压回数据栈即可。

### 代码

```python3
class SortedStack:

    def __init__(self):
        self.stack = []
        
    def push(self, val: int) -> None:
        if not self.stack:
            self.stack.append(val)
        else:
            h = []
            while self.stack and val>self.stack[-1]:
                h.append(self.stack.pop())
            h.append(val)
            while self.stack:
                h.append(self.stack.pop())
            while h:
                self.stack.append(h.pop())
    def pop(self) -> None:
        if not self.stack:
            return -1
        return self.stack.pop()

    def peek(self) -> int:
        if not self.stack:
            return -1
        return self.stack[-1]

    def isEmpty(self) -> bool:
        return len(self.stack)==0


# Your SortedStack object will be instantiated and called as such:
# obj = SortedStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.peek()
# param_4 = obj.isEmpty()
```