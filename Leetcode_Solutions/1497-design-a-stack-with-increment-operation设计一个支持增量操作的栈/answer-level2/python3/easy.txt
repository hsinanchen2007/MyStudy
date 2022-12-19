### 解题思路
此处撰写解题思路

### 代码

```python3
class CustomStack:

    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.size = 0
        self.stack = []


    def push(self, x: int) -> None:
        if self.size < self.maxSize:
            self.size += 1
            self.stack.append(x)


    def pop(self) -> int:
        if not self.stack:
            return -1
        else:
            self.size -= 1
            return self.stack.pop()


    def increment(self, k: int, val: int) -> None:
        for i in range(min(k, self.size)):
            self.stack[i] += val



# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
```