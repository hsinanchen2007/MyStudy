### 解题思路
此处撰写解题思路
1. 创建双端队列
2. 取元素前判断队列是否为空，如果是，则返回-1
### 代码

```python3
class MaxQueue:

    def __init__(self):
        import queue
        self.q = queue.deque()
    def max_value(self) -> int:
        return max(self.q) if self.q else -1

    def push_back(self, value: int) -> None:
        self.q.append(value)

    def pop_front(self) -> int:
        return self.q.popleft() if self.q else -1


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```