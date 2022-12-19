### 解题思路
此处撰写解题思路
简单的条件循环
### 代码

```python3
class Solution:
    def nextClosestTime(self, time: str) -> str:
        hour = int(time[:2])
        minute = int(time[3:])
        candidate = [int(time[0]), int(time[1]), int(time[3]), int(time[4])]
        trans = hour*100+minute

        min_time = 9999
        new_time = str()

        for time1 in list(set(candidate).intersection(set(range(3)))):
            for time2 in candidate:
                if time1 == 2 and time2 > 3:
                    continue
                hour_new = time1 * 10 + time2
                for time3 in list(set(candidate).intersection(set(range(6)))):
                    for time4 in candidate:
                        minute_new = time3 * 10 + time4
                        trans_new = hour_new * 100 + minute_new
                        if trans_new <= trans:
                            tmp = 2400 - trans + trans_new
                        else:
                            tmp = trans_new - trans
                        if tmp < min_time:
                            min_time = tmp
                            new_time = str(time1)+str(time2)+':'+str(time3)+str(time4)
        return new_time


```