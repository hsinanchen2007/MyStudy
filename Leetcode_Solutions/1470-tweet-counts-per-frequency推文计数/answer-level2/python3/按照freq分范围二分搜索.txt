### 解题思路
插入的时候排好序，
查询的时候：
按照时间分钟，小时或者天, 用interval表示，从starttime开始
遍历范围starttime+interval, starttime+2*interval, ... endtime
- 二分查找范围开始时间在队列中的位置s, 以及结束时间在队列中的位置e, 这个时间范围内的推特数量就是e-s

### 代码

```python3
class TweetCounts:

    def __init__(self):
        self.tweet = collections.defaultdict(list)
        self.timemap = {'minute': 60, 'hour': 3600, 'day': 24*3600}

    def recordTweet(self, tweetName, time) -> None:
        bisect.insort(self.tweet[tweetName], time)

    def getTweetCountsPerFrequency(self, freq: str, tweetName, startTime, endTime):
        tweet = self.tweet[tweetName]
        interval = self.timemap[freq]
        res = []
        for l_bound in range(startTime, endTime+1, interval):
            r_bound = min(endTime+1, l_bound+interval)
            res.append(bisect.bisect_right(tweet, r_bound-1) - bisect.bisect_left(tweet, l_bound))
        return res
```