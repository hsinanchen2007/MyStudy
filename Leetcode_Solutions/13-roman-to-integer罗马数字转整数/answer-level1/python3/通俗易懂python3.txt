

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dic = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        num = 0
        carry = dic[s[0]]
        for letter in s:
            if dic[letter] > carry:
                num = num - carry*2
            num = num + dic[letter]
            carry = dic[letter]
        return num
```