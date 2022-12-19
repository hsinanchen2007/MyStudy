### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        newS = ''
        i = 0
        while(i < len(S)):
            newS = newS + S[i]
            num = 1
            while i+1<len(S) and S[i+1] == S[i]:
                num = num+1
                i = i + 1
            newS = newS + str(num)
            i = i + 1
        return newS if len(newS)<len(S) else S
```