### 解题思路
全部字母大写
去除除了字母数字外的符号

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.upper()
        l = len(s)
        if(l==0):
            return True
        temp = []
        for i in range(l):
            if(('A'<=s[i] and s[i]<='Z') or ('0'<=s[i] and s[i]<='9')):
                temp.append(s[i])
        lentemp = len(temp) - 1
        t = 0
        while(t<=lentemp):
            if(temp[t]==temp[lentemp]):
                t += 1
                lentemp -= 1
            else:
                return False
        return True
            
```