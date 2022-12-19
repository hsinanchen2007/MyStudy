```python
class MaxQueue:

    def __init__(self):
        # deque + single_stack
        self.assitStack = collections.deque()
        self.queue = collections.deque()

    def max_value(self) -> int:
        if not self.assitStack: return -1
        return self.assitStack[0]

    def push_back(self, value: int) -> None:
        self.queue.append(value)
        while self.assitStack and value > self.assitStack[-1]:
            self.assitStack.pop()
        self.assitStack.append(value)
        
    def pop_front(self) -> int:
        if not self.queue: return -1
        else:
            top = self.queue.popleft()
            if top == self.assitStack[0]:
                self.assitStack.popleft()
            return top



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```