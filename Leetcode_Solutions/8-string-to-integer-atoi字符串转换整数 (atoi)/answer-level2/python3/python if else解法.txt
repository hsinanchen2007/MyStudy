该题如果用if else 其实就是注重代码完整性，可以设一个flag 来标志是否录入了符号位就解决了题目的大部分，主要涉及的坑就是 不光要判断'-' 还要判断'+'

代码：
```
class Solution:
    def myAtoi(self, str: str) -> int:
        flag = False
        res = ''
        for i in str:
            if i==' '  and flag == False:
                continue
            elif (i=='-' or i=='+') and flag == False:
                res+=i
                flag = True
            elif '0'<=i<='9':
                res+=i
                flag = True
            else:
                break
        if not res or res=='-' or res=='+':  #注意要判断'+'
            return 0
        if int(res)>2**31-1:
            return 2**31-1
        elif int(res) <-2**31:
            return -2**31
        else:
            return int(res)
```

时间复杂度 前96% 应该比正则快一些，但是比较费空间