## 解题思路
比赛的时候样例返回有问题。

本身不难，维护一个字典，把每个用户的时间放入一个数组，查询时，先排序，然后二分找到起始点，向后遍历，要注意的是，如果后面的时间范围中没有推文，也要往数组里补充相应数量的 0。


## 一个问题

感谢 [@xie-wei-9](/u/xie-wei-9/) 同学帮我指出问题。

问题是每次 get 要先排序，排序的平均时间复杂度是 O（nlogn），带来的好处是通过 O（logn） 的一次查找避免了扫描全部元素。整个时间复杂度 O（nlogn）。

实际上如果扫描全部元素时间复杂度是 o（n）。这样看来使用排序+二分查找，时间复杂度反而更高了。

我重新写了一个扫描全部元素的代码，结果发现时间耗时会更长一点。（最后附代码）

![image.png](https://pic.leetcode-cn.com/472d4339ca4f6cdf10490c51a1fbd95a90074351ac7f3e76e7403e1ea55ee8e4-file_1581648932498)

因为实际运行时间和操作顺序、数量还有数据本身都有关系。也和排序的算法具体的实现有关。如果插入操作很少，而查询操作很多，而排序又是插入排序，可能每次重新排序所用的操作数量很少（如果是普通的快速排序，在列表基本有序的情况下排序效率反而很低接近于 n^2)

虽然这样，但我这个代码写的确实是有问题的，写的不好，如果当时我考虑到这点，我不会这么写。可能使用一个有序数据结构存时间会更好（暂时没有更新代码）。

## 代码

### 排序 + 二分代码
```python
import bisect
class TweetCounts:

    def __init__(self):
        self.ul = {}
        
    def recordTweet(self, tweetName: str, time: int) -> None:
        if tweetName not in self.ul: self.ul[tweetName] = []
        self.ul[tweetName].append(time)
        
    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        self.ul[tweetName].sort()
        #print(self.ul[tweetName])
        if freq == 'minute':
            f = 60
        elif freq == 'hour':
            f = 3600
        else:
            f = 86400
        b = bisect.bisect(self.ul[tweetName], startTime-1)
        ans = []
        cnt = 0
        limit = startTime + f
        for n in self.ul[tweetName][b:]:
            #print(n)
            if n > endTime:
                ans.append(cnt)
                r = (endTime - limit) // f
                if limit < endTime:
                    ans.append(0)
                if r > 0:
                    ans += [0] * r
                return ans
            if n >= limit:
                # 0-59 60-119
                ans.append(cnt)
                r = (n - limit) // f
                if r > 0:
                    ans += [0] * r
                limit += (r + 1) * f
                cnt = 0
            cnt += 1
        ans.append(cnt)
        if limit < endTime:
            ans.append(0)
        r = (endTime - limit) // f
        #print(r, limit)
        if r > 0:
            ans += [0] * r
        return ans
```

### 直接遍历代码
```python
import bisect
class TweetCounts:

    def __init__(self):
        self.ul = {}
        
    def recordTweet(self, tweetName: str, time: int) -> None:
        if tweetName not in self.ul: self.ul[tweetName] = []
        self.ul[tweetName].append(time)
        
    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        if freq == 'minute':
            f = 60
        elif freq == 'hour':
            f = 3600
        else:
            f = 86400
        result = [0] * math.ceil((endTime - startTime+1) / f)
        for t in self.ul[tweetName]:
            if startTime <= t <= endTime:
                result[(t - startTime) // f] += 1
        return result
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)