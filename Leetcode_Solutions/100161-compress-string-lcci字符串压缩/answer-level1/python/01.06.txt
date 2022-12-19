### 解题思路
创建空字符串s
遍历字符串S，遇到不同的就在s添加

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        count = 1
        l = len(S)
        if l <= 2:
            return S
        s = ''
        for i in range(1,l):
            if S[i] == S[i-1]:
                count += 1
            else:
                s += S[i-1]+str(count)
                count = 1
            if i == l-1:
                s += S[i]+str(count)
        
        return s if len(S)>len(s) else S
            
```