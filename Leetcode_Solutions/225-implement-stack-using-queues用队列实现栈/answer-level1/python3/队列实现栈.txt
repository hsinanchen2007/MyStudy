### 解题思路
此处撰写解题思路

from queue import Queue

class MyStack:
    def __init__(self):
        self.q=Queue()
    def push(self,x):
        self.q.put(x)
    def pop(self):
        for _ in range(self.q.qsize()-1):
            self.q.put(self.q.get())
        r=self.q.get()
        return r
    def top(self):
        for _ in range(self.q.qsize()-1):
            self.q.put(self.q.get())
        r=self.q.get()
        self.q.put(r)
        return r
    def empty(self):
        return not self.q.qsize()
