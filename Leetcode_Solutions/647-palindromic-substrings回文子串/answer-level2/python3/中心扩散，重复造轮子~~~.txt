```
class Solution:
    def countSubstrings(self, s: str) -> int:
        def get_Center(s,l,r):
            count = 0
            while l>=0 and r<len(s) and s[l]==s[r]:
                l-=1
                r+=1
                count+=1
            return count
        
        
        n = len(s)
        sum1 = 0
        for i in range(len(s)):
            count_even = get_Center(s,i,i)
            count_odd = get_Center(s,i,i+1)
            sum1 = sum1+count_even+count_odd
        return sum1
        
        
        
        
```
