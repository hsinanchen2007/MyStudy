### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I': 1,'V': 5,'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        res=0
        for i in range(len(s)-1,-1,-1):
            if i==len(s)-1 or d[s[i]] >=d[s[i+1]]:
                res+=d[s[i]]
            else:
                res-=d[s[i]]
        return res
```