思路如下：

排序，开始时间从小往大，结束时间从小往大，如果这个范围内的时间都在集合里，就说明不能参加这个会议。否则，将这个时间点加入集合。

```python
class Solution(object):
    def maxEvents(self, events):
        n = len(events)
        res = sorted(events, key = lambda x:(x[1], x[0]))
        s = set()
        length = 0
        for i in res:
            if i[0] not in s:
                s.add(i[0])
                length = length + 1
            else:
                for j in range(i[0]+1, i[1]+1):
                    if j not in s:
                        s.add(j)
                        length = length + 1
                        break
                    else:
                        continue
        return min(length, n)
```