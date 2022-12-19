### 解题思路
逐个字符判断，很一般，也很直接，但逻辑判断太多容易出错。

### 代码

```python3
class Solution:
    def myAtoi(self, s: str) -> int:
        i = 0
        l = 0
        for c in s:
            if c == ' ' and l == 0:
                i +=1
            elif (c == '+' or c == '-') and l == 0:
                l +=1
            elif 48<= ord(c) <= 57 :
                l +=1
            elif l==0:
                return 0
            else:
                break
        try:
            s = int(s[i:i+l])
        except:
            return 0
        if s >= 2**31 -1:
            return 2**31 - 1
        elif s <= -2**31:
            return -2**31
        else:
            return s
            

        


        
```