

```
'''
双指针移动求区间交集
'''

class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        if len(schedule[0]) == 0:
            cur = [Interval(-0x7fffffff, 0x7fffffff)]
        else:
            cur = [Interval(-0x7fffffff, schedule[0][0].start)]
            for k in range(1, len(schedule[0])):
                cur.append(Interval(schedule[0][k - 1].end, schedule[0][k].start))
            cur.append(Interval(schedule[0][-1].end, 0x7fffffff))

        if len(schedule) == 1:
            return cur

        new = []
        for i in range(1, len(schedule)):
            if cur == []:
                return cur

            if len(schedule[i]) == 0:
                s = [Interval(-0x7fffffff, 0x7fffffff)]
            else:
                s = [Interval(-0x7fffffff, schedule[i][0].start)]
                for k in range(1, len(schedule[i])):
                    s.append(Interval(schedule[i][k-1].end, schedule[i][k].start))
                s.append(Interval(schedule[i][-1].end, 0x7fffffff))

            pos1, pos2 = 0, 0
            new = []
            while pos1 < len(cur) and pos2 < len(s):
                s1, e1 = cur[pos1].start, cur[pos1].end
                s2, e2 = s[pos2].start, s[pos2].end
                l_bound, r_bound = max(s1, s2), min(e1, e2)
                if l_bound < r_bound:
                    new.append(Interval(l_bound, r_bound))

                if e1 < e2:
                    pos1 += 1
                elif e1 > e2:
                    pos2 += 1
                else:
                    pos1 += 1
                    pos2 += 1
            cur = new

        return [interval for interval in new if interval.start != -0x7fffffff and interval.end != 0x7fffffff]
```
