对于最大值和插入都是1.pop有的时候是1
```python3
class MaxQueue:

    def __init__(self):
        self.maxval=0
        self.lst=[]
        
    def max_value(self) -> int:
        if len(self.lst):
            return self.maxval
        else :
            return -1

    def push_back(self, value: int) -> None:
        self.lst.append(value)
        if self.maxval<value:
            self.maxval=value
        
            

    def pop_front(self) -> int:
        if len(self.lst):
            if self.lst[0]==self.maxval:
                self.maxval=0
                for i in self.lst[1:]:
                    if self.maxval<i:
                        self.maxval=i
            return self.lst.pop(0)
        else:
            return -1


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```
