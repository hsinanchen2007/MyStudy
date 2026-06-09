贪心算法。使用优先队列，先从最小的一天开始安排。

策略是按照开始日期分组，每一组（也就是每天）只取一个结束时间最早的（也就是会议长度最短的）。然后这把一组其他的所有其他会议的开始时间修改为下一天，放入优先队列排序。

大致是在这样，但是可以有一些小的优化，比如结束日期就是当前处理的一天的会议就可以直接安排上。因为这个会议安排上一定不会影响后面别的会。

整体的贪心策略就是尽可能安排这一天开一个结束日期最早的会。

```python
import queue

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        q = queue.PriorityQueue()
        for e in events:
            q.put(e)
        e = q.get()
        cnt = 1
        cd = e[0] + 1
        while not q.empty():
            e = q.get()
            if e[0] == cd:
                if e[1] >= cd:
                    cd += 1
                    cnt += 1
            elif e[0] > cd:
                cd = e[0] + 1
                cnt += 1
            else: # e[0] < cd
                if e[1] == cd:
                    cd += 1
                    cnt += 1
                if e[1] > cd:
                    e[0] = cd
                    q.put(e)
        return cnt
```


欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)