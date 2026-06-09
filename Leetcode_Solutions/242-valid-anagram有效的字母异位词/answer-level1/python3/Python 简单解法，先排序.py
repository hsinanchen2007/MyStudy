1、先给字符串排序：注意，Python中字符串是不能排序的，所以需要转成list才能排序
2、直接比较排序后的两个字符串是否相等即可
```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #先给字符串排序
        s1 = list(s)
        s1.sort()
        s = "".join(s1)
        t1 = list(t)
        t1.sort()
        t = "".join(t1)
        
        return s == t
```
