### 解题思路
使用re模块的subn函数进行字符替换.subn函数的返回值是替换后的字符串和替换次数.
我们先对两个字符的罗马数字进行替换,可以保证不会出现错误.

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        if not s:
            return 0
        # table={1000:'M',900:'CM',500:'D',400:'CD',100:'C',90:'XC',50:'L',40:'XL',10:'X',9:'IX',5:'V',4:'IV',1:'I'}
        # table=[(v,k) for k,v in table.items()]
        # table.sort(key=lambda t:len(t[0]),reverse=1)
        table=[('CM', 900), ('CD', 400), ('XC', 90), ('XL', 40), ('IX', 9), ('IV', 4), ('M', 1000), ('D', 500), ('C', 100), ('L', 50), ('X', 10), ('V', 5), ('I', 1)]
        # print(table)
        import re
        res=0
        for cha,val in table:
            s,n=re.subn(cha,'',s)
            res+=val*n
        return res

if __name__ == "__main__":
    s="MCMXCIV"
    print(Solution().romanToInt(s))
```