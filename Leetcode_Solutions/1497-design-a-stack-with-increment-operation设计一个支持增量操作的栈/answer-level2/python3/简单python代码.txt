### 解题思路
代码如下

### 代码

```python3
class CustomStack:
    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.nowSize = 0
        self.store = []


    def push(self, x: int) -> None:
        if self.nowSize < self.maxSize:
            self.store.append(x)
            self.nowSize += 1

    def pop(self) -> int:
        if self.nowSize > 0:
            re = self.store.pop()
            self.nowSize -= 1
            return re
        else:
            return -1


    def increment(self, k: int, val: int) -> None:
        real_in = min(k, self.nowSize)
        for i in range(real_in):
            self.store[i] += val



# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
```