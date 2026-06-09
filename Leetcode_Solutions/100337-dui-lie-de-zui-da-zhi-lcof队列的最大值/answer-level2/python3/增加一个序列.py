### 解题思路
如果直接做个变量的存储的话，每次push或pop的时候更新存储的最大值
push更新比较简单，pop就需要搞到去掉pop的数后的最大值，然而一求最大值就又不是O(1)了。
所以再弄个一个序列去按大小顺序存下队列的数值

### 代码

```python3
import queue
class MaxQueue:

    def __init__(self):
        self.deque = queue.deque()
        self.m = -1
        self.templ = []

    def max_value(self) -> int:
        return max(self.deque) if self.deque else -1

    def push_back(self, value: int) -> None:
        if len(self.templ)> 0:
            if value <= self.templ[0]:
                self.templ = [value] + self.templ
            elif value >= self.templ[-1]:
                self.templ.append(value)
            else:
                for i in range(len(self.templ)):
                    if self.templ[i] <= value and self.templ[i+1] >= value:
                        self.templ.insert(i,value)
                        break
        else:
            self.templ.append(value)
        self.deque.append(value)
        if value > self.m:
            self.m = value

    def pop_front(self) -> int:
        if not self.deque:
            self.m = -1
            return -1
        p = self.deque.popleft()
        self.templ.remove(p)
        if p > self.m:
            self.m = self.templ[-1]
        return p




# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```