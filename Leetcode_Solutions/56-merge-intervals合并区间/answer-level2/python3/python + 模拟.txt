```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda x: (x[0], x[1]))
        ans = []
        for a, b in intervals:
            if ans == []:
                ans.append([a, b])
                continue
            if a <= ans[-1][1] and b > ans[-1][1]:
                pre_a = ans[-1][0]
                ans[-1] = [pre_a, b]
            elif a > ans[-1][1]:
                ans.append([a, b])
            
        return ans

```