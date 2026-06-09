

```
class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        obj = collections.Counter(nums)
        obj[-1] = 0
        t = -1
        while True:
            n = len(nums)
            if n < 4:
                return n
            if obj[t] > 1:
                obj[t] -= 1
            else:
                del obj[t]
            s = collections.Counter(obj.values())

            if len(s) > 2:
                t = nums.pop()
                continue
            a,b = list(s.keys()), list(s.values())
            if len(s) < 2:
                if a[0] == 1 or b[0] == 1:
                    break
                t = nums.pop()
                continue
            if 1 in a and s[1] == 1 :
                break
            elif abs(a[0]-a[1]) == 1 and s[max(a)] ==1:
                break
            else:
                t = nums.pop()
        return n
```
