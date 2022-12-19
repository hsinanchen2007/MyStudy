### 解题思路
题目说的很清楚了，所有s中的字符都有一个唯一的映射，并且是一对一映射
那就很简单的想到字典结构了，并且要保证唯一映射，那么可以用一个list来存放已经存在的value
由于是一对一的映射，我们并不需要两个字典来保存，只需要一个字典d来存储s到t的映射和一个list L来存储已经存在的映射结果就行了

### 代码

```python3
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d={}
        L=[]
        for i in range(len(s)):
            if s[i] not in d:
                if t[i] in L:
                    return False
                L.append(t[i])
                d[s[i]]=t[i]
            elif d[s[i]]!=t[i]:
                return False
        return True
```