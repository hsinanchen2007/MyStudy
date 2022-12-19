思路
直观的解法是按照效率进行降序排序，每个人作为最低效率时，在其左侧找出至多K - 1个最大速度即可(再加上这个人的速度组成K个)，这一过程可以用堆，时间复杂度O(nlg(k-1))

代码
```python
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        persons = [(speed[i], efficiency[i]) for i in range(n)]
        persons = sorted(persons, key=lambda x:x[1], reverse=True)
        ans = 0
        spd, s = [], 0
        for j in range(n):
            if len(spd) > k-1:
                s -= heapq.heappop(spd)
            ans = max(ans, (s + persons[j][0]) * persons[j][1])
            heapq.heappush(spd, persons[j][0])
            s += persons[j][0]
        return ans % 1000000007
```

