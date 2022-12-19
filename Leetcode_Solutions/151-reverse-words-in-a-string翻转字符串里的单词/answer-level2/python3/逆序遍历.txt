### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        ans = ''
        start,end = 0,0
        for i in range(len(s)-1,-1,-1):
            if s[i] != ' ' and(i==len(s)-1 or s[i+1]==' '):end = i
            if s[i]!=' ' and (i==0 or s[i-1]==' '):start = i;ans += s[start:end+1]+' '
        return ans[:-1]
```