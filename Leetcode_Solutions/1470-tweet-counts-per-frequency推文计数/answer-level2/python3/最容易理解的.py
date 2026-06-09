### 解题思路
代码自注释

### 代码

```python3
class TweetCounts:

    def __init__(self):
        self.usertweets = collections.defaultdict(list)
        

    def recordTweet(self, tweetName: str, time: int) -> None:
        self.usertweets[tweetName].append(time)

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        if freq == "minute":
            delta = 60
        elif freq == "hour":
            delta = 3600
        else:
            delta = 3600 * 60

        ans = [0] * ((endTime - startTime) // delta + 1)
        for time in self.usertweets[tweetName]:
            if startTime <= time <= endTime:
                ans[(time - startTime) // delta] += 1 
        
        return ans


```