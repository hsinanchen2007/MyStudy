### 解题思路
此处撰写解题思路

### 代码
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n,m=len(num1),len(num2)
        res=[0]*(m+n+10)
        num1=''.join(reversed(num1))
        num2=''.join(reversed(num2))
        for i in range(n):
            for j in range(m):
                res[i+j]+=int(num1[i])*int(num2[j])
        for i in range(len(res)-1):
            res[i+1]+=res[i]//10
            res[i]=res[i]%10
        reversed(res)
        res=[str(i) for i in res]
        res="".join(reversed(res))
        i=0
        while res[i]=='0' and i<len(res)-1:
            i+=1
        return res[i:]
