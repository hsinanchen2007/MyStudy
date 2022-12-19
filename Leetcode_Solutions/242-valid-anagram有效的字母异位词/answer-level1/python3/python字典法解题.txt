首先断两字符串长度是否相等，不相等返回False
再判count_s,count_t用**collections模块**中的*Counter函数*生成了一个键为字符串字母键值为该字母出现次数的字典
判断键相同的键值是否相等
若全部相等返回True
```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count_s=collections.Counter(s)
        count_t=collections.Counter(t)
        if len(s)!=len(t):
            return False
        for key in count_s:
            if count_s[key]!=count_t[key]:
                return False
        return True
```
