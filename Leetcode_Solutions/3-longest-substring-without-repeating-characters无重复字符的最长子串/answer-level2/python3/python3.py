```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n,ans,left= len(s),0,-1
        list_1 = [None for _ in range(128)]
        for right in range(len(s)):
            if list_1[ord(s[right])] == None:
                list_1[ord(s[right])] = right
            else:
                if left < list_1[ord(s[right])]:
                    left = list_1[ord(s[right])]
                list_1[ord(s[right])] = right
            ans = max(ans,right-left)
        return ans


```
