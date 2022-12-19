### 解题思路
字典+滑动窗口
效率并不高

### 代码

```python3
from collections import Counter
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words: return []
        pattern=Counter(words)
        res=[]
        wsLen=len(words)
        wLen=len(words[0])
        for i in range(len(s)-wLen*wsLen+1):
            cur=[s[i+j*wLen:i+(j+1)*wLen] for j in range(wsLen)]
            if Counter(cur)==pattern: res.append(i)
        return res
```

### 问题
看到字符串就想用正则表达式
但是不知道出了什么问题，求指教

```python3
from collections import Counter
import re
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words: return []
        pattern1=Counter(words)
        pattern2=""
        res=[]
        length=len(words)*len(words[0])
        for i in words:
            pattern2=pattern2+"|"+i
        for i in range(len(s)-length+1):
            cur=s[i:i+length-1]
            if Counter(re.findall(pattern2,cur))==pattern1: res.append(i)
        return res
```