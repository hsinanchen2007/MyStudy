```python
class TweetCounts:

    def __init__(self):
        self.dic = collections.defaultdict(list)
        self.intervals = {
            'minute': 60,
            'hour': 3600,
            'day': 86400
        }
    

    def recordTweet(self, tweetName: str, time: int) -> None:
        self.dic[tweetName].append(time)

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        interval = self.intervals[freq]
        # Note: 这里需要用数组， 因为某个间隔的推文数可能为0， 避免使用map
        res = [0] * ((endTime - startTime) // interval  + 1)
        for time in self.dic[tweetName]:
            if startTime <= time <= endTime:
                res[(time - startTime) // interval] += 1
        return res
# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)
```