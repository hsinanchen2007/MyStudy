### 解题思路
对s循环，如果循环到v是I,X,C,则判断v的下个字母v+s[i+1]是不是在h里面，下次循环就设置c标签跳过

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        a = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        h = {'IX':9,'IV':4,'XL':40,'XC':90,'CM':900,'CD':400}
        b = 0
        c = True  # 设置标签跳过循环
        for i,v in enumerate(s):
            if not c:
                c = True   # 设置标签跳过循环
                continue
            if v in ['I','X','C'] and i <= len(s)-2:  # 判断索引会不会超过s，控制在倒数第二位
                if v+s[i+1] in h:
                    c = False  # 设置标签跳过循环
                    b += h[v+s[i+1]]
                else:
                    b += a[v]
            else:
                b += a[v]
        return b



```