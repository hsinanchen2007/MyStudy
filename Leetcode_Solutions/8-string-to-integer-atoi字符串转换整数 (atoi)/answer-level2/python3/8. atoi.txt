### 解题思路
此题关键在于考虑周全所有的情况，并进行分类，题目描述中没有出现对“+”的处理，容易翻车；这份代码以第一次遇到有效地字符为界，再进行更细致的情况考察。

### 代码

```python3
class Solution:
    def myAtoi(self, s: str) -> int:
        if not s:
            return 0
        flag = False
        sgn = 1
        result = 0
        for c in s:
            if not flag :
                if c>='0' and c<='9':
                    result = result*10+ord(c)-ord('0')
                    flag=True
                elif c=='-':
                    sgn=-1
                    flag=True
                elif c==' ':
                    continue
                elif c=='+':
                    flag=True
                else:
                    return 0
            else:
                if c >= '0' and c <= '9':
                    result = result * 10 + ord(c) - ord('0')
                else:
                    break
        result *= sgn
        result = -2**31 if result<-2**31 else result
        result = 2**31-1 if result>2**31-1 else result
        return result
```