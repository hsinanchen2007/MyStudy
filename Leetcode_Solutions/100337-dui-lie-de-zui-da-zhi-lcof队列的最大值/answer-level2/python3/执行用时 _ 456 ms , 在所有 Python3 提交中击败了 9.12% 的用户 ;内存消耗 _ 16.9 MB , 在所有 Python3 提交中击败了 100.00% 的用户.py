### 解题思路
列表简单操作。

### 代码

```python3
class MaxQueue:

    def __init__(self):
        self.a = []

    def max_value(self) -> int:
        if self.a != []:
            return max(self.a)
        else:
            return -1

    def push_back(self, value: int) -> None:
        return self.a.append(value)

    def pop_front(self) -> int:
        if self.a != []:
            return self.a.pop(0)
        else:
            return -1


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```