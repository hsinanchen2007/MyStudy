
    class Solution:
        def lengthOfLastWord(self, s: str) -> int:
            a = 0
            if not s:return a
            flag = len(s)-1
            while  flag>0 and s[flag]==" ":
                flag-=1
            for i in range(flag,-1,-1):
                if s[i]==" ":
                    break
                a+=1
            return a