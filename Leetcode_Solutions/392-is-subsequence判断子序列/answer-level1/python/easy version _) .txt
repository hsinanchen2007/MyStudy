### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        count = 0
        length = len(s)
        for i in range(len(s)):
            for w in range(count, len(t)):
                if s[i] == t[w]:
                    count = w + 1
                    print(count)
                    length = length - 1
                    break
        if length == 0:
            return True 
        else:
            return False 


                
```