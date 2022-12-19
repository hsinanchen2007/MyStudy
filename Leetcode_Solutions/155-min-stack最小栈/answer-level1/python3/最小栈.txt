### 解题思路
此处撰写解题思路
使用一个最小栈解决问题，忽略大值，只储存小值

attention： 最小栈需要在相等的时候也存入，因为pop时的缘故。
### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.helper = []
        

    def push(self, x: int) -> None:
        self.data.append(x)
        if self.data and (not self.helper or x <= self.helper[-1]):
            self.helper.append(x)


    def pop(self) -> None:
        if self.data:
            if self.data[-1] == self.helper[-1]:
                self.helper.pop()
            return self.data.pop()

    def top(self) -> int:
        return self.data[-1]

    def getMin(self) -> int:
        return self.helper[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```