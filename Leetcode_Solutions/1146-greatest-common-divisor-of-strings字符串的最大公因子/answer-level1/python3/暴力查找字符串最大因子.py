### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) < len(str2):
            return self.gcdOfStrings(str2, str1)
        tl = 0
        if str1[0]!=str2[0]:
            return ''
        if len(str1)==len(str2):
            if str1==str2:
                return str1
        else:
            tl = len(str2)
        t = ''
        x = ''
        for i in range(tl):
            t += str2[i]
            if str1==(t*(len(str1)//len(t))) and str2 == (t*(len(str2)//len(t))):
                x = t
        return x



```