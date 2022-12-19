### 解题思路
此处撰写解题思路

### 代码

```python3
class MaxQueue:

    def __init__(self):
        self.queue = []
        # aux左边第一个元素就是最大值
        # 一样的思路 是不知道哪里错了
        self.aux = []

    def max_value(self) -> int:
        if not self.aux:
            return -1
        return self.aux[0]

    def push_back(self, value: int) -> None:
        self.queue.append(value)
        # 辅助单调递减队列
        while self.aux and value > self.aux[-1]:
            self.aux.pop(-1)
        self.aux.append(value)
        # print(self.queue)
        # print(self.aux)
    def pop_front(self) -> int:
        if not self.queue:
            return -1
        tmp = self.queue.pop(0)
        if tmp == self.aux[0]:
            self.aux.pop(0)
        return tmp
```