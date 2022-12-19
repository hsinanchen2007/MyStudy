### 解题思路 后面添加值也影响前面栈底最大元素，特殊想象添加一个最大值，则统统出栈
此处撰写解题思路

### 代码

```python
class MaxQueue:

    def __init__(self):
        self.q = collections.deque()#数据队列
        self.p = collections.deque()#单调递减栈（准确说是非增）

    def max_value(self) -> int:
        return not self.q and -1 or self.p[0] #数据队列为空，返回-1，否则返回单调栈第一个元素

    def push_back(self, value: int) -> None:
        self.q.append(value)
        while self.p and value > self.p[-1]:
            self.p.pop()
        self.p.append(value)

    def pop_front(self) -> int:
        if not self.q:
            return -1
        self.q[0] == self.p[0] and self.p.popleft() #数据队列元素为最大值时才出栈单调栈元素
        return self.q.popleft()
        


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```