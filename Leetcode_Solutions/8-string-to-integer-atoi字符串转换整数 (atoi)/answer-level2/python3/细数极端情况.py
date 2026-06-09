极端情况
1.全空
2.除开头空格外有效字符仅+ -
需注意的地方：
i作为索引指向末尾时，需提前break，否则会out of str index
```
   def myAtoi(self, str: str) -> int:
        if len(str)==0:#str本身为空
            return 0
        i=0
        while str[i]==' ' and i<len(str):
            i+=1
            if i==len(str):#i已指向字符串末尾，需提前break，否则str[i]将会报错
                break
        if i==len(str):#str全为空格的情况
            return 0
        if str[i]!='+' and str[i]!='-' and (str[i]<'0' or str[i]>'9'):
            return 0
        flag=1
        result=0
        if str[i]=='+':
            i=i+1
        elif str[i]=='-':
            i=i+1
            flag=0
        if i==len(str):#str除去开头空格仅有+ -的情况
            return 0
        while str[i]>='0' and str[i]<='9' and i<len(str):
            result=result*10+int(str[i])
            i+=1
            if i==len(str):#i已指向字符串末尾，需提前break，否则str[i]将会报错
                break
        if flag==0:
            result=result*(-1)
        if result>2**31-1:
            return 2**31-1
        if result<-2**31:
            return -2**31
        return result
```
