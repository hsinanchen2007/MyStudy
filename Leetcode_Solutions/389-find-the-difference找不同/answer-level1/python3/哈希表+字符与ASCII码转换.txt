方法一，哈希表，分别遍历两个字符串即可。

```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        res = {}
        for i in s:
            if res.get(i):
                res[i] += 1  #记录s中的字符出现次数
            else:
                res[i] = 1
        for i in t:
            if res.get(i):   #消除字典中存在的字符
                res[i] -= 1
            else:
                return i     #字典中没有相同字符，则返回该字符
```

方法2，字符与ASCII码值转换。
```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        a = 0
        b = 0
        for i in s:
            a += ord(i)
        for i in t:
            b += ord(i)
        return chr(b-a)
```

