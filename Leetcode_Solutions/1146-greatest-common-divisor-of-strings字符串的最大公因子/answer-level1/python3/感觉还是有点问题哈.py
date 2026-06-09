### 解题思路
利用了python3的内置函数替换，因为整除的字符串长度不超过两个字符串的最小值，因此通过迭代替换，当两个字符串都为空时，字符串即符合要求

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        s1 = len(str1)
        s2 = len(str2)
        s = min(s1,s2)
        while s :
            if str1.replace(str1[0:s],'')=='' and str2.replace(str1[0:s],'')=='':
                return str1[0:s]
            s -=1
        return ''
```