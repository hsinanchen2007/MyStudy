直接看代码吧，算是暴力过的。
```
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort(key = lambda x: (x[1], x[0]))
        # print(events)
        num = set()
        for event in events:
            num.add(event[0])
            num.add(event[1])
        right = max(num)
        left = min(num)
        
        flag = [False for _ in range(right + 1)]
        
        for event in events:
            if not flag[event[0]]:
                flag[event[0]] = True
            else:
                for i in range(event[0] + 1, event[1] + 1):
                    if not flag[i]:
                        flag[i] = True
                        break
        count = 0
        for f in flag:
            if f:
                count += 1
        return count
```


