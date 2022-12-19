```python3
class Solution:
    def sortString(self, s: str) -> str:
        a=[0]*26
        lst=''
        for i in s:
            a[ord(i)-ord('a')]+=1
        while sum(a):
            for i in range(26):
                if a[i]:
                    a[i]-=1
                    lst+=chr(97+i)
            for i in reversed(range(26)):
                if a[i]:
                    a[i]-=1
                    lst+=chr(97+i)
        return lst
```
