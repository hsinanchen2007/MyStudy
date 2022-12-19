```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) > len(s): return ""
        # Time complexity : O(N)
        # Space complexity : O(N)
        matches = 0
        dic = collections.defaultdict(int)
        for ch in t: dic[ch] += 1
        pre, length, end = -1, float('inf'), 0
        for i in range(len(s)):
            if s[i] in dic:
                dic[s[i]] -= 1
                if dic[s[i]] == 0: matches += 1
            if matches == len(dic):
                while True:
                    pre += 1
                    if s[pre] in dic: 
                        dic[s[pre]] += 1
                        if dic[s[pre]] > 0:
                            matches -= 1
                            break
                if i - pre + 1 < length:
                    length = i - pre + 1
                    end = i
        return s[end - length + 1: end + 1] if length != float('inf') else ''
```