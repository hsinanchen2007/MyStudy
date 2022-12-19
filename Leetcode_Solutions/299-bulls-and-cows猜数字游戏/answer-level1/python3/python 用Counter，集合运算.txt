```
class Solution(object):
    def getHint(self, secret, guess):
        a=b=0
        from collections import Counter
        s = Counter(secret)
        g = Counter(guess)
        x=len(guess)
        for i in range(x):
            if guess[i]==secret[i]:
                a+=1
        for k in s&g:
            b+=min(s[k],g[k])
        return  '{0}A{1}B'.format(a, b-a)
```
