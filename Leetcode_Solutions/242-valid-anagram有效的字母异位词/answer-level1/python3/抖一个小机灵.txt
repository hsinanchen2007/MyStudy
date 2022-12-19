抖一个小机灵
元素和次数分别放在字典里面 然后对字典item的集合做异或 不为空说明俩字符串不全一样
```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) !=len(t):
            return False
        if not s and not t:
            return True
        dic1={}
        for i in list(set(list(s))):
            dic1[i]=s.count(i)
        dic2={}
        for i in list(set(list(t))):
            dic2[i]=t.count(i)
        res=set(dic1.items())^set(dic2.items())
        return len(list(res))==0
```