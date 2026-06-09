维护一个区间数组，然后先二分左值，在判断边界和插入的可行性即可。

```python
class MyCalendar:

    def __init__(self):
        self.data = [(0, 0), (1e9 + 4, 1e9 + 4)]

    def book(self, start: int, end: int) -> bool:
        le = len(self.data)
        if le == 2:
            self.data.insert(1, (start, end))
            return True
        l, r = 1, le - 2
        while l < r:
            mid = (r - l) // 2 + l
            if self.data[mid][0] > start:
                r = mid - 1
            elif self.data[mid][0] < start:
                l = mid + 1
            else:
                return False    
        le, re = (l - 1, l) if self.data[l][0] > start else (l, l + 1) 
        #print("区间: ", start, end)
        #print("数据: ", self.data)
        #print("边界: ", le, re)
        #print(self.data[le][1] <= start, self.data[re][0] >= end)
        #print("")
        if self.data[le][1] <= start and self.data[re][0] >= end:
            self.data.insert(re, (start, end))    
            return True
        return False    

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
```