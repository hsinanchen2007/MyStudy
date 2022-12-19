### 解题思路

![image.png](https://pic.leetcode-cn.com/c2516cc5fc63c047e6455566ce4fadf44eac33ecc08977d3ffa4518092ad0c52-image.png)


- 双队列法
设置两个队列，最大长度为301
第一个队列存放时间戳
第二个存放时间戳的累计和

每次取的时候，使用二分查找，找出时间戳队列的两个索引，然后使用累积和相减的方式求值

### 代码

```python3
from collections import deque
import bisect


class HitCounter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.timestamp = deque(maxlen=301)
        self.timestamp_accumulate = deque(maxlen=301)
        self.timestamp.append(0)
        self.timestamp_accumulate.append(0)

    def hit(self, timestamp: int) -> None:
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        """
        if timestamp == self.timestamp[-1]:
            self.timestamp_accumulate[-1] += 1
        else:
            self.timestamp.append(timestamp)
            self.timestamp_accumulate.append(self.timestamp_accumulate[-1] + 1)

    def getHits(self, timestamp: int) -> int:
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        """
        right = bisect.bisect_right(self.timestamp, timestamp) - 1
        left = bisect.bisect_left(self.timestamp, timestamp - 299) - 1
        left_sum = self.timestamp_accumulate[left] if left >= 0 else 0
        right_sum = self.timestamp_accumulate[right] if right >= 0 else 0
        return right_sum - left_sum



# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
```