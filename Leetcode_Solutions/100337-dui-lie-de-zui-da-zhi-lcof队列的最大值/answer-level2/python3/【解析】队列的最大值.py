### 解题思路
使用Python的内置方法即可。

### 代码

```python3
class MaxQueue:

    def __init__(self):
        self.size = 0
        self.maxval = None
        self.data = []


    def max_value(self) -> int:
        if self.size == 0:
            return -1
        return max(self.data)


    def push_back(self, value: int) -> None:
        if self.maxval is None:
            self.maxval = value
        elif value >= self.maxval:
            self.maxval = value
        self.data.insert(0, value)
        self.size += 1


    def pop_front(self) -> int:
        if self.size == 0:
            return -1
        tmp = self.data[len(self.data) - 1]
        self.data.pop()
        if tmp == self.maxval and self.data != []:
            self.maxval = max(self.data)
        self.size -= 1
        return tmp



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```