**思路：**

以给的投票时间序列`times`为索引，记录每次投票后的胜出候选人，在查询的时候采用二分法即可在对数时间内返回正确结果。计算胜出候选人的时候，用`hashmap`记录每个候选人的票数，并用变量记录当前优胜者和最大票数，如果投票后，当前投给的候选人票数大于等于当前优胜者的票数，那么替换当前优胜者和最大票数。

构造时间复杂度$O(N)$ 查询时间复杂度$O(logN)$

空间复杂度$O(N)$

**代码：**

```python
class TopVotedCandidate:

    def __init__(self, persons, times):
        """
        :type persons: List[int]
        :type times: List[int]
        """
        l = len(times)
        self.t = times
        self.winner = [persons[0]] * l
        d = dict()
        winner_bynow = persons[0]
        max_ticket = 1
        d[persons[0]] = 1
        for i in range(1, l):
            if persons[i] in d:
                d[persons[i]] += 1
            else:
                d[persons[i]] = 1
            if d[persons[i]] >= max_ticket:
                winner_bynow = persons[i]
                max_ticket = d[persons[i]]
            self.winner[i] = winner_bynow
            
    def q(self, t):
        """
        :type t: int
        :rtype: int
        """
        index = bisect.bisect(self.t, t) - 1
        return self.winner[index]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
```