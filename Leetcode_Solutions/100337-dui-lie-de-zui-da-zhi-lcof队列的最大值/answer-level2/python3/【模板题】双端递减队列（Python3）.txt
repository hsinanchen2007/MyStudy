
## 思路

我们维护一个正常的队列queue，这样`push_back`, `pop_front` 直接操作正常队列即可。

问题在于如何在$O(1)$ 时间 实现`max_value`? 我们的想法是维护一个递减的双端队列deque。

- 每次queue入队列的时候，我们deque也入队列，入队列之前我们清除队尾的比入队的元素小的元素。 一句话来说，我们的目的就是`维持 deque保持递减性质不变`
- 每次queue pop的时候，我们的deque不一定也要出队列。当且仅当deque的队首元素和queue队首元素一致时候，我们才需要执行deque的出队列的操作
- 这样`max_value`我们只需要返回deque的队首元素即可，至此我们终于实现了`$O(1)$ 时间 实现max_value`
- 
## 代码


```python
class MaxQueue:

    def __init__(self):
        self.queue = []
        self.deque = []
        

    def max_value(self) -> int:
        return self.deque[0] if self.deque else -1
        

    def push_back(self, value: int) -> None:
        self.queue.append(value)
        while self.deque and value > self.deque[-1]:
            self.deque.pop(-1)
        self.deque.append(value)

        

    def pop_front(self) -> int:
        front = self.queue and self.queue.pop(0)
        if self.deque and self.deque[0] == front:
            self.deque.pop(0)
        return front or -1
```

**复杂度分析**
- 时间复杂度：$O(1)$
- 空间复杂度：$O(N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)