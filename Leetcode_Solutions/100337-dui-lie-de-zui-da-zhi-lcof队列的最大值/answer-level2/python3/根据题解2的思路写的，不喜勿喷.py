### 解题思路

记录一下几个误区，第一pop_left里的第二个if循环是必要的，因为第一个if循环判断条件是deque，如果没有第二个if循环控制deque的长度，在
多次弹出以后，会报错；
第二  push_back(self, value: int) -> None:
        while self.deque and self.deque[-1] < value:
            self.deque.pop()
里deque.pop()函数可以改成deque.popleft(),不过需要修改求最大值的部分

    def max_value(self) -> int:
        return max(self.listHelp) if self.listHelp else -1


    def push_back(self, value: int) -> None:
        while self.deque and self.deque[-1] < value:
            self.deque.popleft()
        self.deque.append(value)
        #self.queue.put(value)
        self.listHelp.append(value)
希望对你有帮助！




### 代码

```python3
import queue
class MaxQueue:

    def __init__(self):
        self.deque = queue.deque()
        #self.queue = queue.Queue()
        self.listHelp = []

    def max_value(self) -> int:
        return self.deque[0] if self.deque else -1


    def push_back(self, value: int) -> None:
        while self.deque and self.deque[-1] < value:
            self.deque.pop()
        self.deque.append(value)
        #self.queue.put(value)
        self.listHelp.append(value)

    def pop_front(self) -> int:
        if not self.deque:
            return -1
        #ans = self.queue.get()
        ans = self.listHelp.pop(0)
        if ans == self.deque[0]:
            self.deque.popleft()
        return ans




# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```