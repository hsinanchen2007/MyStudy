
## 思路:

思路一:库函数

思路二:倍降指数

这道题有点像求解[斐波那契数列](https://baike.baidu.com/item/%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97/99145?fr=aladdin),所以可以用递归和迭代的方法,如下面两种方法,

递归
```python 
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0 : return self.myPow(1 / x, -n)
        if n == 0: return 1
        if n == 1:
            return x
        return x * self.myPow(x, n - 1)
```

迭代
``` python 
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1 / x
            n = -n
        if n == 0:
            return 1
        res = 1
        for _ in range(n):
            res *= x
        return res
```

但是如果**x = 1.00000,n = 2147483648**,这就会超时,所以我们采用数学小技巧

比如$2^{10} = {2^2}^5 = 4^5 = 4 ×{4^4} = 4 × 8^2 = ....$大家一定发现这里面小技巧了,我们可以通过不断缩小指数,来降低复杂度.

------


## 代码:

递归

```python [1]
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0 : return self.myPow(1 / x, -n)
        if n == 0: return 1
        if n % 2 == 0:
            return self.myPow(x*x, n//2)
        else:
            return x * self.myPow(x*x, n//2)
```



```java [1]
class Solution {
    public double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        if (n == Integer.MIN_VALUE)
            return myPow(x*x, -(n/2));
        return (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
    }
}
```



迭代

```python [2]
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1 / x
            n = -n
        if n == 0:
            return 1
        res = 1
        while n :
            if n % 2 == 0:
                n //= 2
                x *= x
            else:
                res *= x
                n -= 1
        return res
```

