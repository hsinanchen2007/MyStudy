### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        a=0
        b=0
        for i in range(len(s)):
            for j in range(a,len(t)):
                if t[j]==s[i]:
                    a=j+1
                    b=b+1
                    break
        if b==len(s):
            return True
        else:
            return False

```