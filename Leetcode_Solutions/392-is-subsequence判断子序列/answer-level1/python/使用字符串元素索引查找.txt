使用字符串查找元素的索引，然后对母串切片：
index = t.index(item) -->  t = t[index+1:]；
如果所有元素都可以检索到，返回True；
反之，返回False。

runtime:28ms, 超过python3的99%。

```
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        for i in range(len(s)):
            if s[i] in t:
                t = t[t.index(s[i])+1:]
            else:
                return False
        return True
```
