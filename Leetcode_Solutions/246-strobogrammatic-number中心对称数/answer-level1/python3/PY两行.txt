```
class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        d={'0': '0', '1': '1', '6': '9', '8': '8', '9': '6'}
        return all(num[i] in d and d[num[i]]==num[~i] for i in range(len(num)//2))\
            and (len(num)%2==0 or num[len(num)//2] in ('0','1','8'))
```
