### 解题思路

创建 self.s = [] 作为栈。但是 s 中每个元素第一个是真实的值，第二个是增加的值，每次 increment 操作，不直接增加栈里元素，而是记录在栈里相应位置的元素的这个列表中，直到 pop 的才加起来，而且累加到前面一个元素上。

### 代码

```python
class CustomStack:

    def __init__(self, maxSize: int):
        self.size = 0
        self.maxSize = maxSize
        self.s = []

    def push(self, x: int) -> None:
        if self.size < self.maxSize:
            self.s.append([x, 0])
            self.size += 1


    def pop(self) -> int:
        if self.size == 0:
            return -1
        x, inc = self.s.pop()
        if len(self.s) > 0:
            self.s[-1][1] += inc
        self.size -= 1
        return x + inc


    def increment(self, k: int, val: int) -> None:
        if self.size > 0:
            k -= 1
            k = min(k, self.size-1)
            self.s[k][1] += val



# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
```