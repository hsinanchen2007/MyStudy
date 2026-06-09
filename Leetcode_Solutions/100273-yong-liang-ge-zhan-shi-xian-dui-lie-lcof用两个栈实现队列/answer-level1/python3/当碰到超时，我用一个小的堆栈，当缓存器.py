```python3
import queue
class CQueue:
#我正常写的用一个堆栈来保存，用另一个来中间帮忙折叠一次，发现一个问题超时我的第一次更改，多用一个堆栈，#当做10的缓存

#'''
    
    def __init__(self):
        self.q1=queue.LifoQueue()
        self.q2=queue.LifoQueue()
        self.q3=queue.LifoQueue()
        self.countq3=0

    def appendTail(self, value: int) -> None:
        if self.countq3<=20:
            
            self.q3.put(value)
            self.countq3+=1
        
            
        else:
            self.countq3=0
            while not self.q1.empty():
                self.q2.put(self.q1.get())
            while not self.q3.empty():
                self.q1.put(self.q3.get())
            while not self.q2.empty():
                self.q1.put(self.q2.get())

    def deleteHead(self) -> int:
        if self.q1.empty() :
            while not self.q3.empty():
                self.q1.put(self.q3.get())
        self.countq3=0
        if self.q1.empty():
            return -1        
        return self.q1.get()
```
