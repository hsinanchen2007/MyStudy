### 解题思路
时间复杂度：O（n）
空间复杂度：O（n）

### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.sorted_vals = []
        self.vals = []


    def push(self, x: int) -> None:
        self.vals.append(x)
        if not self.sorted_vals:
            self.sorted_vals.append(x)
            return
        for ind, i in enumerate(self.sorted_vals):
            if x < i:
                self.sorted_vals.insert(ind, x)
                break
        else:
            self.sorted_vals.append(x)

    def pop(self) -> None:
        if not self.vals:
            return
        ind = -1
        try:
            ind = self.sorted_vals.index(self.vals[-1])
            del self.sorted_vals[ind]
            del self.vals[-1]
        except ValueError as e:
            return


    def top(self) -> int:
        if not self.vals:
            return None
        t = self.vals[-1]
        return t


    def getMin(self) -> int:
        if not self.sorted_vals:
            return None
        t = self.sorted_vals[0]
        return t



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```