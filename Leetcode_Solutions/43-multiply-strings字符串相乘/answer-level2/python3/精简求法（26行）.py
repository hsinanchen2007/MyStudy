第一个函数multiply为主函数
第二个函数用于一个整数乘以一个字符串：例如2*‘123’ = ‘246’
第三个函数即两个字符串相加，即第415题的题解。
```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0": #处理特殊情况
            return '0'
        num2 = num2[::-1]
        res = '0'
        for index,i in enumerate(num2):
            res = self.addtwostrings(res,self.int_mul_str(int(i),num1)+'0'*index)
        return res
    def int_mul_str(self,num,str_):
        i,car,ji = len(str_)-1,0,''
        while i>=0:
            car,temp = divmod(num*int(str_[i])+car,10)
            ji = str(temp)+ji
            i-=1
        return str(car)+ji if car else ji
    def addtwostrings(self,num1,num2):
        i,j,car,res = len(num1)-1,len(num2)-1,0,''
        while i>=0 or j>=0:
            x1 = int(num1[i]) if i>=0 else 0
            x2 = int(num2[j]) if j>=0 else 0
            car,temp = divmod(x1+x2+car,10)
            res = str(temp)+res
            i-=1
            j-=1
        return str(car)+res if car else res
```
