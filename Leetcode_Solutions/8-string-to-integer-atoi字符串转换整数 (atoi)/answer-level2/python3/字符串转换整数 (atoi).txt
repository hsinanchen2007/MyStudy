
该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

```
class Solution:
    def myAtoi(self, str: str) -> int:
        str=str.lstrip()#去掉左边的空格
        output=0 #设置默认输出为0
        if str=="":
            return 0
        #判断是否存在符号位，起始点会有不同
        i=2 if str[0]=='-' or str[0]=='+' else 1
        
        while i<=len(str):#一直转换为整数直到报错为止
            try:
                output=int(str[:i])
                i+=1
            except:
                break
        if output<-2147483648 :
            return -2147483648
        if output>2147483647:
            return 2147483647
        
        return output       
```
输入: "   -42"
输出: -42
输入: "4193 with words"
输出: 4193
输入: "words and 987"
输出: 0