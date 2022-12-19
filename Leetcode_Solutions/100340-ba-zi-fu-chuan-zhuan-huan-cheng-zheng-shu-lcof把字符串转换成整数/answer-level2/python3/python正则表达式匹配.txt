### 解题思路
https://blog.csdn.net/u010412858/article/details/83062200
```
^ 匹配字符串开始
[\+\-] 有‘+’或者'-'
? 表示前面的字符可有可无
\d+ 表示有1个或者多个数字
更多请看https://blog.csdn.net/u010412858/article/details/83062200
```


### 代码

```python3
class Solution:
    def strToInt(self, str: str) -> int:
        ans=int(*re.findall('^[\+\-]?\d+',str.lstrip()))#必须要加一个*号
        return min(ans,2**31-1) if ans>0 else max(ans,-2**31)

        #return max(min(int(*re.findall('^[\+\-]?\d+',str.lstrip())),2**31-1),-2**31)


            
```