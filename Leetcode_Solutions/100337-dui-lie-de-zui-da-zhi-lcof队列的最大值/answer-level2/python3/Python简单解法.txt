### 解题思路
Python大法好！
1、首相明白队列是先进先出，pop_front是pop出最前面的数字，可以此时可以考虑list自身的反转[::-1]；
2、记住每次pop_front之后，要将p0p出的数删除掉，
3、时间复杂度有点高，但是能通过

### 代码
```
class MaxQueue:

    def __init__(self):
        self.data = []
    

    def max_value(self) -> int:
        if len(self.data)>0:
            return max(self.data)
        else:
            return -1

    

    def push_back(self, value: int) -> None:
        self.data.append(value)


    def pop_front(self) -> int:
        if len(self.data)>0:
            popData = self.data[::-1].pop()
            self.data.remove(popData)
            return popData
        else:
            return -1

        

# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```
