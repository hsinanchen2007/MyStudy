### 代码

```python3
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        from collections import defaultdict
        left = 0
        right = 0
        match = 0
        res = []
        window = defaultdict(int)
        needs = defaultdict(int)
        for c in p:
            needs[c] += 1
        while right < len(s):
            c1 = s[right]
            if c1 in needs:
                window[c1] += 1
                if window[c1] == needs[c1]:
                    match += 1
            right += 1
            while match == len(needs):
                if right - left == len(p):
                    res.append(left)
                c2 = s[left]
                if c2 in needs:
                    window[c2] -= 1
                    if window[c2] < needs[c2]:
                        match -= 1
                left += 1
        return res
```