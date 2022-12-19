### 解题思路
如果字符串长度不一样，不符合题意
把每个字符出现的次数用字典记录
如果2这两个字典一样，符合题意

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        dir1,dir2={},{}
        for i in s:
            if i not in dir1:
                dir1[i]=1
            elif i in dir1:
                dir1[i]+=1
        for s in t:
            if s not in dir2:
                dir2[s]=1
            elif s in dir2:
                dir2[s]+=1
        if dir1==dir2:
            return True
        else:
            return False
```