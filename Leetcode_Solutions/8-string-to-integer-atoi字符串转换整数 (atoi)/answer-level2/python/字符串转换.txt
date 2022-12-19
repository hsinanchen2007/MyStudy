### 解题思路
1）先将字符串两边去空格

2）判断去完空格的字符串str，是否为空，空的话返回0；不为空的话判断第一个字符str[0]是否为“+”，“-”，区别符号位，再使str=str[1:];另外如果str[0]不满足str[0]>='0' and str[0]<='9'的要求的话，直接返回0

3) 对于剩下的str，判断每个字符x是否满足x>='0' and x<='9'的要求，满足的话累加到res上，不满足直接break跳出循环

4）判断res是否越界


### 代码

```python
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str=str.strip()
        if str=='':return 0
        flag=1
        if str[0]=="+":
            str=str[1:]
        elif str[0]=='-':
            str=str[1:]
            flag=-1
        elif str[0]<'0' and str[0]>'9':return 0
        
        res=0
        for x in str:
            if x<='9' and x>='0':
                res=10*res+int(x)
            else:break
        res*=flag
        if res>2**31-1:return 2**31-1
        if res<-2**31:return -2**31
        return res
```