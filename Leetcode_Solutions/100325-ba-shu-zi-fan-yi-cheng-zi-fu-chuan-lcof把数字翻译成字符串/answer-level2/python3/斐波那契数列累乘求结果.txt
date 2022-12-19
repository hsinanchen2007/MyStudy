算法思路:从前到后找出所有连续数列求Fibonacci(连续序列的长度)的值累乘
Fibonacci(X) = 1,1,2,3,5,8,13,21,34......(X = 0,1,2,3,4,5,6,7,8......)
先举个例子:
12258
1225 8 Fibonacci(4) * Fibonacci(1) = 5

设:12258中形如1225,8这样的序列成为**连续序列**
1.要么相连的两位都有两种翻译方式，比如1225
    即连续两位的组合在0-26之间(并且前一位不为0,因为01,02,03这种序列只有一种翻译方式不能算作连续序列)
2.要么序列长度为1，比如8

再举几个例子:
12251225 
1225 1225  Fibonacci(4) * Fibonacci(4) = 5 * 5 = 25

12215130
12215 13 0  Fibonacci(5) * Fibonacci(2) * Fibonacci(1) = 2 * 8 * 1 = 16

12340142
123 4 0 14 2  Fibonacci(3) * Fibonacci(1) * Fibonacci(1) * Fibonacci(2) * Fibonacci(1) = 6 

至于长度为X的连续序列翻译方式为什么是Fibonacci(X)?
翻译要么走一步要么走两步，到达终点有几种方式？
这和小青蛙跳台阶是一样的，是Fibonacci数列的经典例子。

代码如下:
```python []
class Solution:
    def translateNum(self, num: int) -> int:
        num = str(num)
        res = cur = 1
        for i in range(1,len(num)):
            if(num[i-1]+num[i]<'26' and num[i-1]!='0'):
                cur+=1
            else:
                res *= self.Fibonacci(cur)
                cur = 1
        res *= self.Fibonacci(cur)
        return res

    def Fibonacci(self,n):
        a = b = 1
        for _ in range(n):
            a,b = b,a+b
        return a
```

