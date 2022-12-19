
把每一个时间点的hit数记录到queue中，queue存放tuple，表示（timestamp，hit_count）
每次hit的时候，检查queue左边的tuple时间有没有过期，如果有就移除
- 然后检查queue最有一个tuple的时间是不是和当前hit的时间一样，
- 如果一样就hit_count加一
- 否则向queue中添加一个新的tuple，(timestamp, 1), 1表示这个时间是最新的，hit了一次
每次get的时候，也需要检查queue左边的过期时间戳
```python3
class HitCounter:

    def __init__(self):
        self.queue = collections.deque()
        self.count = 0

    def removeExpired(self, timestamp):
        while self.queue and self.queue[0][0] + 300 <= timestamp:
            self.count -= self.queue[0][1]
            self.queue.popleft()
        
    def hit(self, timestamp: int) -> None:
        self.removeExpired(timestamp)
        if self.queue and self.queue[-1][0] == timestamp:
            self.queue[-1][1] += 1
        else:
            self.queue.append([timestamp, 1])
        self.count += 1
        

    def getHits(self, timestamp: int) -> int:
        self.removeExpired(timestamp)
        return self.count
```