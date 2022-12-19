### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        lis = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        result = 0
        for i in range(len(s)):
            if i > 0:
                if lis[str(s[i])] <= lis[str(s[i-1])]:
                    result = result + lis[str(s[i])]
                if lis[str(s[i])] > lis[str(s[i-1])]:
                    result = result + lis[str(s[i])] - 2*(lis[str(s[i-1])])
            else:
                result += lis[str(s[i])]
        return(result)

```