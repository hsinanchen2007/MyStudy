### 解题思路
做完题看了大家的题解，才发现大家在查数据的时候，用队列只存了5分钟的值。

用列表存了时间戳和对应的前缀和次数。

在查找的时候，根据时间戳计算开始和结束的时间段，在列表中二分查找开始和结束的时间段。

用的二分会找到小于等于目标值的第一个值。
如果没有查到合适的数据，会一直查到列表的最左边第一个数，所以需要判断一下查找到的是第一个数的时候，是不是想要的结果。

### 代码

```python3
class HitCounter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.cnt = []

    def hit(self, timestamp: int) -> None:
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        """
        if self.cnt:
            if self.cnt[-1][0] == timestamp:
                self.cnt[-1][1] += 1
            else:
                self.cnt.append([timestamp, 1+self.cnt[-1][1]])
        else:
            self.cnt.append([timestamp, 1])

    def getHits(self, timestamp: int) -> int:
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        """
        if not self.cnt:
            return 0
        
        start = timestamp - 300
        end = timestamp
        
        l, r = 0, len(self.cnt) - 1
        while l < r:
            mid = (l+r+1) >> 1
            if self.cnt[mid][0] <= start:
                l = mid
            else:
                r = mid - 1
                
        left = l
        
        l, r = 0, len(self.cnt) - 1
        while l < r:
            mid = (l+r+1) >> 1
            if self.cnt[mid][0] <= end:
                l = mid
            else:
                r = mid - 1
                
        right = l
        
        # print(self.cnt, left, right)
        # 其实不会发生这种情况，即查的是 x 时刻的数据，但是在 x 之后才有数据
        if self.cnt[right][0] > end:
            return 0
        
        # 如果查的时间的开始时间比记录的最早的都早，那用结束时间的值即可
        if left == 0 and start < self.cnt[left][0]:
            return self.cnt[right][1]

        # 结束时间减去开始时间的值
        return self.cnt[right][1] - self.cnt[left][1]


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
```