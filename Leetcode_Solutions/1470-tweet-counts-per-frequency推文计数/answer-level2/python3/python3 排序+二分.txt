### 解题思路
唯一技术：二分确定>=startTime的最左边界的index

直接遍历不太好意思。。。

### 代码

```python3
class TweetCounts:

    def __init__(self):
        import heapq
        from collections import defaultdict
        self.d = defaultdict(list)
        self.interver = {"minute":60, "hour":3600, "day":3600 * 24}

    def recordTweet(self, tweetName: str, time: int) -> None:
        self.d[tweetName].append(time)

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        delta = self.interver[freq]
        record = self.d[tweetName]
        record.sort()
        span = endTime - startTime + 1
        n = span // delta + 1 if span % delta != 0 else span // delta
        
        res = [0] * n
        '''
        # O(n)遍历 可能会超时
        for time in record:
            if startTime <= time <= endTime:
                res[(time - startTime) // delta] += 1
            elif time > endTime:break
        '''
        # 二分查找record中第一个>=startTime的下标
        #print(record, startTime)
        index = 0
        if startTime != 0:
            l, r = 0, len(record)
            while l < r:
                m = (l + r) // 2
                #print(l,r,m,record[m])
                if record[m] >= startTime:
                    r = m
                elif record[m] < startTime:
                    l = m + 1
            index = l
        #print(index)
        for i in range(index, len(record)):
            if record[i] > endTime:break
            res[(record[i] - startTime) // delta] += 1   
        return res
        


# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)
```