### 解题思路
如题

### 代码

```python3
class CustomStack:

    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.curSize = 0
        self.stack = []


    def push(self, x: int) -> None:
        if self.curSize < self.maxSize:
            self.stack.append(x)
            self.curSize += 1



    def pop(self) -> int:
        if self.curSize > 0:
            self.curSize -= 1
            return self.stack.pop()
        else:
            return -1


    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, self.curSize)):
            self.stack[i] += val




# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
```