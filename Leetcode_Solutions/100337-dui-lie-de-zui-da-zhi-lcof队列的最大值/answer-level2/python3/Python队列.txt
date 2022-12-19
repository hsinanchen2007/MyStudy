### 解题思路


### 代码

```python3
import queue
class MaxQueue:

    def __init__(self):
        self.myqueue=queue.deque() # 直接使用队列框架，方便的是可以直接使用self.myqueue就可以判断队列是不是空

    def max_value(self) -> int:
        return max(self.myqueue) if self.myqueue else -1

    def push_back(self, value: int) -> None:
        self.myqueue.append(value)
        return None

    def pop_front(self) -> int:
        return self.myqueue.popleft() if self.myqueue else -1


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```