### 解题思路
此处撰写解题思路
```python
^：匹配字符串开头
[\+\-]：代表一个+字符或-字符
?：前面一个字符可有可无
\d：一个数字
+：前面一个字符的一个或多个
\D：一个非数字字符
*：前面一个字符的0个或多个
https://blog.csdn.net/u010412858/article/details/83062200 更多正则匹配公式
```

### 代码

```python3
class Solution:
    def strToInt(self, str: str) -> int:
        cs=["0","1","2","3","4","5","6","7","8","9","+","-"]#先定义一个字符串
        res=""
        str=str.strip()#去除字符串2端的空字符
        if not str:
            return 0
        print(str[0])
        if str[0] not in cs:#（1）先对第一个字符进行判断
            return 0
        else:#（2）再对之后的字符进行判断
            cs.remove("+")
            cs.remove("-")
            res+=str[0]
            for i in range(1,len(str)):
                if str[i] not in cs:
                    break
                else:
                    res+=str[i]
        if res == '+' or res == '-': return 0#（3）对结果是否越界进行判断
        return min(2**31-1,int(res)) if int(res)> 0 else max(-2**31,int(res))


            
```