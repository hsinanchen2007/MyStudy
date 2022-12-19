class Solution:
    def longestPrefix(self, s: str) -> str:
        if len(s)<=1:
            return ''
        else:
            max_length=0
            for i in range(1,len(s)):
                if s[0:i]==s[len(s)-i:len(s)]:
                    max_length=i
            return s[0:max_length]
        
        