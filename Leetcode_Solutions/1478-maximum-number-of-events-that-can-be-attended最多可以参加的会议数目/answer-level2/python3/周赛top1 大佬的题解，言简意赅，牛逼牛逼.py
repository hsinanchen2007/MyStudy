以下纯属个人解读，如有不当之处，请各位批评指正！多向大佬学习！参考周赛top1大佬的代码，大佬如此简洁的代码，五体投地，佩服佩服，看懂了，太妙了，原来是贪心：对于某一天i，参加满足条件的最早结束的会议。

1.首先对会议倒序排序（最早开始且最早结束的会议放在列表最后面，之所以倒序是因为每次要对events进行pop操作）；

2.对于每一天（对应每一个i），将所有满足第i天开始的会议的**结束时间**压入小根堆end）；

3.此时要判断，小根堆的最小元素是否小于i（小根堆存放的是会议的结束时间，且end[0]为最早结束的时间），若小于i（因为第i天参加会议，所以会议的结束时间必须大于i才能参加），则弹出；继续判断，直到小根堆中所有元素都大于i（即结束时间大于i，那么小根堆中的所有会议在第i天都可以参加）

4.最后，既然end中有那么多的参加选择，根据贪心算法，对于每一个i，将满足条件的最早结束的会议时间弹出end小根堆（即弹出end[0]）,也就是说每一天都选择参加满足条件里最早结束的会议。这样其他的会议才会有更有可能被参加。

heapq 模块相关操作自行查阅理解

```
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        ans = 0
        end = list()
        events = sorted(events,reverse=True)
        for i in range(1,100010,1):
            while events and events[-1][0] == i:
                heapq.heappush(end, events.pop()[1])
            while end and end[0] < i:
                heapq.heappop(end)
            if end:
                heapq.heappop(end)
                ans += 1
        return ans
```
