```python
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        dic = collections.defaultdict(int)
        if k == 0: return 0
        i, ans, cnt = 0, 0, 0
        for st in s:
            dic[st] += 1
            cnt += 1
            while len(dic) == k + 1:
                dic[s[i]] -= 1
                i += 1
                cnt -= 1
                if dic[s[i - 1]] == 0:
                    del dic[s[i - 1]]
                    break
            ans = max(ans, cnt)
        return ans            
```