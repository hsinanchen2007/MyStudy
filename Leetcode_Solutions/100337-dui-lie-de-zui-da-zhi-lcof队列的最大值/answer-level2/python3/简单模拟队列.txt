### 解题思路
简单模拟队列

### 代码

```python3
class MaxQueue:

    def __init__(self):
        self.val = []


    def max_value(self) -> int:
        if self.val:
            return max(self.val)            
        else:
            return -1


    def push_back(self, value: int) -> None:
        self.val.append(value)
        return None


    def pop_front(self) -> int:
        if self.val:
            k =  self.val[0]
            self.val = self.val[1:]    
            return k        
        else:
            return -1



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```