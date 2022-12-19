```
class Solution:
    def minMeetingRooms(self, I: List[List[int]]) -> int:
        I.sort()
        sched=[]
        for s,e in I:
            assigned=False
            for rm in sched:
                if rm[-1][1]<=s:
                    rm.append((s,e))
                    assigned=True
                    break
            if not assigned:
                sched.append([(s,e)])
        return len(sched)
```
