```
class Solution(object):
    def numDecodings(self, s):
        if s[0] == "0": return 0
        pre, M = 1, 10**9 + 7
        cur = 1 if s[0] <> "*" else 9
        for i in range(1, len(s)):
            tmp = cur
            if s[i] == "*":
                cur = cur * 9
                if s[i-1] == "1": cur = (pre*9 + cur) % M
                elif s[i-1] == "2": cur = (pre*6 + cur) % M
                elif s[i-1] == "*": cur = (pre*15 + cur) % M
            else:
                if s[i] == "0":
                    if s[i-1] == "1" or s[i-1] == "2": cur = pre % M
                    elif s[i-1] == "*": cur = pre*2 % M
                    else: return 0
                elif s[i-1] == "1" or (s[i-1] == "2" and ord(s[i])<=ord("6")): cur = (cur+pre)%M
                elif ord(s[i])<=ord("6") and s[i-1] == "*": cur = (cur+pre*2)%M
                elif ord("6")<ord(s[i]) and s[i-1] == "*": cur = (cur+pre)%M
            pre = tmp
        return cur % M
```
