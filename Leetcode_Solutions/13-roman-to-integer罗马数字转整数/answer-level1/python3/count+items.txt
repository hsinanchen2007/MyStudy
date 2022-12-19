### 解题思路
1. 取两字符数字并去除
2. 取单字符数字并按数计算

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        simple_dict={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        multi_dict={'IV':4,'IX':9,'XL':40,'XC':90,'CD':400,'CM':900}
        result=0

        for k,v in multi_dict.items():
            result+=v if k in s else 0
            s=s.replace(k,'')

        for k,v in  simple_dict.items():
            result+=v*s.count(k)
            
        return result
```