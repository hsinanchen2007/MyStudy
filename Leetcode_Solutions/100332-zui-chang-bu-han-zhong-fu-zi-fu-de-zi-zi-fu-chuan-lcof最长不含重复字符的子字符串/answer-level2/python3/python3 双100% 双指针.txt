class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d=set()
        n=len(s)
        count=0
        l,r=0,0
        while r<n:
            if s[r] not in d:
                d.add(s[r])
                count=max(count,len(d))
                r+=1
            else:
                while s[l]!=s[r]:
                    d.remove(s[l])
                    l+=1
                l+=1
                r+=1
        return count
