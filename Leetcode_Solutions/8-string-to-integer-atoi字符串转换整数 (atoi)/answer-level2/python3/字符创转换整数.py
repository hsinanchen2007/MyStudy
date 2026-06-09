### 解题思路
此处撰写解题思路
先对字符串去空格
在使用正则表达式匹配
正则表达式为[+-]?\d*  
### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        s = str.strip()
        if len(s) == 0:
            return 0
        if s[0]!='-' and s[0]!='+' and not s[0].isnumeric():
            return 0
        res = int(re.match('[+-]?\d*',s).group()) if (re.match('[+-]?\d*',s).group()!='-') and (re.match('[+-]?\d*',s).group()!='+') else 0
        if res > 2**31-1:
            return 2**31-1
        elif res < -2**31:
            return -2**31
        else:
            return res
```