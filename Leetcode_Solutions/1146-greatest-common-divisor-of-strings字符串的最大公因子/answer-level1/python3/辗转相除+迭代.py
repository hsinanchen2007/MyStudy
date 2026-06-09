原理：
除数ABABAB/被除数ABAB ----> 余数 AB  (余数当作下一个式子的被除数)
除数ABAB / 被除数AB ---->  余数AB
AB/AB没有余数，返回AB


```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        n1 = len(str1)
        n2 = len(str2)
        p = 0
        while p < n1 and p < n2:
            if str1[p] == str2[p]:
                p += 1
            else:return ""
        if   p<n2 :  return self.gcdOfStrings(str1,str2[p:])
        elif p<n1 :  return self.gcdOfStrings(str2,str1[p:])
        elif p==n1 and p==n2: return str1
```
