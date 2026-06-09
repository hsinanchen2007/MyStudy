```python
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        dic = collections.defaultdict(int)
        i = 0
        cnt, res = 0, 0
        for st in s:
            dic[st] += 1
            cnt += 1
            while len(dic) == 3:
                dic[s[i]] -= 1
                cnt -= 1
                i += 1
                if dic[s[i - 1]] == 0: 
                    del dic[s[i - 1]]
                    break
            res = max(res, cnt)
        return res
    
```