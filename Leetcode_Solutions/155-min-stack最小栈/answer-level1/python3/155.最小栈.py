### 解题思路
- 列表实现栈，列表元素（cur_min,val）；cur_min当前元素及栈中元素的最小值
- 压栈要修改self.min_,出栈也要修改self.min_(特别注意栈空的时候，self.min_要恢复为None)

### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_ = None
        self.stack = []


    def push(self, x: int) -> None:
        if self.min_ is None:
            self.min_ = x
        else:
            self.min_ = min(self.min_,x)
        self.stack.append((self.min_,x))
        



    def pop(self) -> None:
        self.stack.pop()
        if self.stack:
            self.min_ = self.stack[-1][0]
        else:self.min_ = None


    def top(self) -> int:
        return self.stack[-1][1]


    def getMin(self) -> int:
        return self.min_



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```