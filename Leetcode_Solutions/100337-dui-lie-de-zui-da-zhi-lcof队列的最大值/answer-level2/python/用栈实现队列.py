### 解题思路
此处撰写解题思路

### 代码

```python3
class MaxQueue:
    def __init__(self):
        self.queue = []

    def max_value(self) -> int:
        imax = float('-inf')
        for i in range(len(self.queue)):
            if self.queue[i] > imax:
                imax = self.queue[i]
        return -1 if not self.queue else imax

    def push_back(self, value: int) -> None:
        self.queue.append(value)


    def pop_front(self) -> int:
        if not self.queue:return -1
        return self.queue.pop(0)



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```