思路：
1.num1与num2中的每一位高精度乘得到len(num2)个中间结果
2.在第i个中间结果后面补上i个0(i从0开始)
3.所有中间结果进行高精度加得到最终结果。
代码；
```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        def mul(s1,s2):
            s=0
            s2=int(s2)
            result=''
            for i in range(len(s1)-1,-1,-1):
                s1_i=int(s1[i])
                t=s1_i*s2+s
                s=int(t/10)
                t=t%10
                result=str(t)+result
            if s>0:
                result=str(s)+result
            return result
        def add(s1,s2):
            m=max(len(s1),len(s2))
            if len(s1)<m:
                s1='0'*(m-len(s1))+s1
            if len(s2)<m:
                s2='0'*(m-len(s2))+s2
            s=0
            result=''
            for i in range(m-1,-1,-1):
                t=int(s1[i])+int(s2[i])+s
                s=int(t/10)
                t=t%10
                result=str(t)+result
            if s>0:
                result=str(s)+result
            return result
        tt=[]
        if len(num1)==0:
            num1='0'
        if len(num2)==0:
            num2='0'
        if num1=='0' or num2=='0':
            return '0'
        for i in range(len(num2)-1,-1,-1):
            num2_i=num2[i]
            temp=mul(num1,num2_i)
            tt.append(temp+(len(num2)-1-i)*'0')
        result=''
        for i in range(len(tt)):
            result=add(result,tt[i])
        return result
```
