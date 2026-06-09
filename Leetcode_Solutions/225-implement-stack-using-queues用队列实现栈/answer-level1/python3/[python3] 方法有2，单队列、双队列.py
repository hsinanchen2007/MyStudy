### 解题思路
python3 本题可以使用2种方法：
1、from queue import Queue 队列，更能体现和栈区别，代码会复杂些
2、from collections import deque 双向队列，特殊列表，代码相对简单
### 代码
```python3
方法1：
from queue import Queue

class MyStack:

    def __init__(self):
        self.q = Queue()

    def push(self, x):
        self.q.put(x)
        for _ in range(self.q.qsize() - 1):
            self.q.put(self.q.get())
        
    def pop(self):
        return self.q.get()

    def top(self):
        r = self.q.get()
        self.q.put(r)
        for _ in range(self.q.qsize() - 1):
            self.q.put(self.q.get())
        return r
    
    def empty(self):
        return not self.q.qsize()       

方法2：
from collections import deque

class MyStack:

    def __init__(self):
        self.q = deque()

    def push(self, x):
        self.q.append(x)
        
    def pop(self):
        return self.q.pop()

    def top(self):
        r = self.q.pop()
        self.q.append(r)
        return r
    
    def empty(self):
        return not self.q