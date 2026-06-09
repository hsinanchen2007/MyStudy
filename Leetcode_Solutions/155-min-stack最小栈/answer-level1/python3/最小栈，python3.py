### 解题思路
此处撰写解题思路

### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.small = []
        

    def push(self, x: int) -> None:
        if self.small:
            self.small.append(min(self.small[-1], x))
        else:
            self.small.append(x)
        self.data.append(x)
        
        

    def pop(self) -> None:
        if self.data and self.small:
            del self.data[-1]
            del self.small[-1]

        

    def top(self) -> int:
        if self.data:
            return self.data[-1]
        return None
        

    def getMin(self) -> int:
        if self.small:
            return self.small[-1]
        return None
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```