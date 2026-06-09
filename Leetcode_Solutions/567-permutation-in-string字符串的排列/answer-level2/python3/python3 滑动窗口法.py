```
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l1,l2 = len(s1),len(s2)
        c1 = collections.Counter(s1)
        c2 = collections.Counter()
        cnt = 0
        left = right = 0
        while right < l2:
            c2[s2[right]] += 1
            right += 1
            if all(map(lambda x: c2[x] == c1[x], c1.keys())):
                return True
            while right - left + 1 > l1:
                c2[s2[left]]  -= 1
                left += 1
        return False
```

