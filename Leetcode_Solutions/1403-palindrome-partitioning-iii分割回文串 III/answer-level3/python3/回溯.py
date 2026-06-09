对于字符串s,切成k段,则第一段可以有len(s)-k+1种切法(因为后面k-1段至少要有k-1个字符)，分别为s[0:i] (1<= i <=len(s)-k+1).
遍历第一段的所有情况，后面的s[i:]是子问题，用回溯的方法得出所有分割情况。
````python
from functools import lru_cache
class Solution:
    @lru_cache(1800)
    def revToPd(self,s): #求将一个字符串转为回文所需的字符数
        lg = len(s)
        i = 0
        j = lg-1
        ans = 0
        while i <= j:
            if s[i] != s[j]:
                ans += 1
            i+=1
            j-=1
        return ans
    @lru_cache(1800)
    def palindromePartition(self, s: str, k: int) -> int:
        if k == 1:
            return self.revToPd(s)
        lg = len(s)
        if lg == k:
            return 0
        ans = float("inf")
        for i in range(lg-k+1):
            ans = min(ans,self.revToPd(s[:i+1])+self.palindromePartition(s[i+1:],k-1))
        return ans
```
