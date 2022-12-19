
```py
class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        tlmax = [[] for _ in range(len(times))]
        d = collections.defaultdict(int)
        tmp = 0
        for i, (t, p) in enumerate(zip(times, persons)):
            d[p] += 1               #记录当前最大票数
            if d[p] >= tmp:         #票数大于等于之前的最大票数时，胜选人易主
                tmp = d[p]
                tlmax[i] = [t, p]   #记录当前时间的胜选人
            else:
                tlmax[i] = tlmax[i - 1]
        self.tlmax = tlmax
                
    def q(self, t: int) -> int:
        return self.tlmax[bisect.bisect(self.tlmax, [t, float('inf')]) - 1][1]#二分查找并返回胜选人编号

```
