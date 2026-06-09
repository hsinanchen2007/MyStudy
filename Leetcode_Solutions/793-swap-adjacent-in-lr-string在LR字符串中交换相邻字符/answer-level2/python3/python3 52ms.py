> 一种类似于贪心的思路。每次不满足时，找到最近的交换使其满足，然后继续判断
```python
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        
        if len(start) != len(end):
            return False
        
        start,end = list(start),list(end)
        n = len(start)
        i = 0
        while i < n:
            if start[i] == end[i]:
                i += 1
            else:
                if start[i] == 'R' and end[i] == 'X':
                    j = i+1
                    while j < n and end[j] == 'X':
                        j += 1
                    if j < n and end[j] == 'R':
                        end[i],end[j] = end[j],end[i]
                    else:
                        return False
                elif start[i] == 'X' and end[i] == 'L':
                    j = i+1
                    while j < n and start[j] == 'X':
                        j += 1
                    if j < n and start[j] == 'L':
                        start[i],start[j] = start[j],start[i]
                    else:
                        return False
                else:
                    return False
                i += 1
            #print(start,end)
        return True
```