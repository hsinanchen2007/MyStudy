![image.png](https://pic.leetcode-cn.com/93a80420d9e64853b0ed7ade036ec3ce7b7100aca3a245dc9dab00db795d1801-image.png)


```
'''
端点作为事件处理，遇到开始事件累加增加1，反之遇到结束事件累加减小1，
答案是中间结果中最大的累加值
'''

from sortedcontainers import SortedDict
class MyCalendarThree:

    def __init__(self):
        self.event_cnt = SortedDict()

    def book(self, start: int, end: int) -> int:
        if start not in self.event_cnt:
            self.event_cnt[start] = 0
        self.event_cnt[start] += 1

        if end not in self.event_cnt:
            self.event_cnt[end] = 0
        self.event_cnt[end] -= 1

        cnt, ans = 0, -1
        for val in self.event_cnt.values():
            cnt += val
            ans = max(ans, cnt)
        return ans
```
