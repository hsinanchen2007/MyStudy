### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        ls = [0]*26
        lt= [0]*26
        for i in s:
            ls[ord(i)-ord('a')]+=1
        for i in t:
            lt[ord(i)-ord('a')]+=1
        res = 0
        for i in range(26):
            res+=abs(ls[i]-lt[i])
        return res//2
```