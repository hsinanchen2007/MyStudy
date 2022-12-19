### 解题思路
计数切片，找到每个反转后字母的下标，可能包含相同的字母所以每个加a才能找到相同字母的不同下标

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        mx=s[0] if s else ''
        
        for i in range(len(s)):
            a=0#下标计数器
            while s[::-1][a:-i-1].find(s[i])!=-1:
                a=s[::-1][a:-i-1].index(s[i])+a
                if s[i+1:len(s)-a-1] == s[::-1][a+1:-i-1]:
                    if len(mx)<len(s)-a-i+1:
                        mx=s[i:len(s)-a]
                        a=0
                        break
                    break
                else:
                    a+=1
            if len(mx)>=len(s[i:]):
                return mx 
        return mx

```