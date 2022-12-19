### 解题思路
一个正常队列保存正常元素，另一个队列保存单调递减元素。
非正常队列入队时：将新加入的值与前值相比较，删除小于新加入值的前值，后推入新值。
非正常队列出队时：将表头元素对比正常队列的表头元素，如果一样就弹出表头，不一样就不操作
核心思想：递减队列中的每一个值valuemax都代表着，正常队列中从表头开始到与valuemax相等值片段的最大值。

### 代码

```python3
class MaxQueue:

    def __init__(self):
        self._head = 0
        self._mhead =0
        self._num = 0
        self.queue = []
        self.maxqueue = []

    def max_value(self) -> int:
        if self.maxqueue[self._mhead:]:
            return self.maxqueue[self._mhead]
        else:
            return -1

    def push_back(self, value: int) -> None:
        self.queue.append(value)
        self._num += 1

        while self.maxqueue[self._mhead:] and value > self.maxqueue[-1]:
            self.maxqueue.pop()
        self.maxqueue.append(value)


    def pop_front(self) -> int:
        if self._num != 0:
            res = self.queue[self._head]
            self._head += 1
            self._num -= 1
            if self.maxqueue[self._mhead:] and self.maxqueue[self._mhead] == res:
                self._mhead += 1
            return res
        else:
            return -1

# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```