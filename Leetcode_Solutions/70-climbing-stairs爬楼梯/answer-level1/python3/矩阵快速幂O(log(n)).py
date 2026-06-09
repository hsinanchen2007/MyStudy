本题是两步递推，假设已经知道ans(n-1)和ans(n-2),那么ans(n)=ans(n-1)+ans(n-2)。举例来说，1个台阶只有一种上法，两个台阶也是一种，三个台阶可以是1+2或者2+1，四个台阶可以是2+2或者3+1，五个台阶可以是3+2或者4+1……
对这种递推，可以用矩阵实现，n步递推的乘子就是n*n的矩阵。而矩阵的幂的计算可以用快速幂优化到O(log(n))。据我个人所知，python计算指数的符号是重载了快速幂算法的，但是显然矩阵的幂应该没有，而且快速幂算法是RSA公钥体系等现代重要理论的基础算法，了解一下还是很有必要
```
class Solution:
    def climbStairs(self, n: int) -> int:
        def multi(x:List[List[int]], y:List[List[int]]) -> List[List[int]]:
            m = len(x)
            n = len(x[0])
            s = len(y[0])
            tmp = [[0 for i in range(s)]for j in range(m)]
            for i in range(m):
                for j in range(n):
                    for k in range(s):
                        tmp[i][k] += x[i][j]*y[j][k]
            return tmp
        fib = [[0,1],[1,1]]
        a = [[1],[1]]
        while n>0:
            if n & 1 == 1:
                a = multi(fib,a)
            fib = multi(fib,fib)
            n = n//2
        return a[0][0]
```