### 解题思路
每次push检查比较一下, 看是否有新的最小值
每次pop出来的时候, 判断一下是不是把min_index位置的元素给pop了, 是的话要O(n)时间重新找一个最小元素出来.

push: O(1)时间, O(1)空间
pop: O(n)时间, O(1)空间
其他getMin和top操作当然都是O(1)时间啦.

### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.min_index = 0

    def push(self, x: int) -> None:
        self.data.append(x)
        if self.data[self.min_index] > x:
            self.min_index = len(self.data) - 1

    def pop(self) -> None:
        arrange_flag = False
        if len(self.data) - 1 == self.min_index:
            arrange_flag = True
        e = self.data.pop()
        self.arrange()
        return e

    def top(self) -> int:
        return self.data[-1]

    def getMin(self) -> int:
        if len(self.data) < 0:
            return None
        return self.data[self.min_index]

    def arrange(self) -> None:
        if len(self.data) <= 0:
            return
        min_index = 0
        for i in range(len(self.data)):
            if self.data[i] < self.data[min_index]:
                min_index = i
        self.min_index = min_index
        
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```