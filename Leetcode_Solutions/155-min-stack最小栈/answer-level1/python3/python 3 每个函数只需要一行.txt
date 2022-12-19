### 解题思路
每结点都储存当结点值、到此结点的最小值、上一结点包含信息。
每个函数只需要一行

### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.point = (None, None, None)  # (value, min, last point)

    def push(self, x: int) -> None:
        self.point = (x, min(x, self.point[1]) if self.point[1] is not None else x, self.point)

    def pop(self) -> None:        
        self.point = self.point[2]

    def top(self) -> int:
        return self.point[0]

    def getMin(self) -> int:
        return self.point[1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```