### 解题思路
atoi大概上分为三步
1.判断字符串的第一个非空字符之后的子字符串是否符合一个整数的规则，从而判断可否转换成整数，其中可以转换的有三种情况
 1)由+号开头，接下来的是0到9范围的字符，将正负号标示置为1
 2)没有+-号开头，第一个非空是0到9范围的字符，将正负号标示置为1
 3)由-号开头，接下来的是0到9范围的字符，将正负号标示置为-1
 4)其余的不能转换返回0

2.从子字符串开始处转换为整数，每读取一位整数字符，之前的result*=10，再加上读到的这位整数

3.根据正负号标示转换为正负数
### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        limit=2147483647
        n= len(str)
        if n==0:
            return 0
        begin=0
        neg=0
        for i in range(n):
            if str[i]!=' ': 
                if str[i]=='+' and i+1<n and str[i+1]>='0' and str[i+1]<='9':
                    begin = i+1
                    neg = 1
                    break
                elif str[i]>='0' and str[i]<='9':
                    begin = i
                    neg = 1
                    break
                elif str[i]=='-' and i+1<n and str[i+1]>='0'and str[i+1]<='9':
                    begin = i+1
                    neg = -1
                    break
                else:
                    return 0
        else:
            return 0
        result=0
        for i in range(begin,n):
            if str[i]>='0'and str[i]<='9':
                result*=10
                result+=int(str[i])
            else: break
        if neg==1:
            if result<=limit:
                return result
            else:
                return limit
        elif neg==-1:
            if result <= limit+1:
                return 0-result
            else:
                return 0-(limit+1)
```