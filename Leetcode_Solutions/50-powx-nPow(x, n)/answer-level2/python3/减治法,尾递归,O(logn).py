- 执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
- 内存消耗 :6.8 MB, 在所有 C 提交中击败了76.63%的用户   

这道题采用减治法(减常因子为2)的思想，减常因子的减治法可以看做是分治法，但只对减小规模后的一个部分求解：
 
减治也就是指:原本需要算`a^n`，现在我们只需要算`a^(n/2)`就行了，而另一半的`a^(n/2)`我们不用再去算了，因为我们知道`a^n=a^(n/2)*a^(n/2)`，如果n为奇数，则`a^n=a^((n-1)/2)*a^((n-1)/2)*a`，只需要算`a^((n-1)/2)`就行。    
   
依照这个想法，要计算`a^(n/2)`只需要算`a^(n/4)`，... ，最后到要计算`a^2`只需要知道`a`就行。也就是我们每次都把问题规模减半，问题数量不变仍为1，`T(n)=T(n/2)+1`，这里的`T(n/2)`就指剩下的一半大小规模的问题的时间，`1`指计算`a^k*a^k`的常数时间，所以时间复杂度为`T(n)=O(log(n))`。

结合尾递归速度会非常快：
```C []
/* 实现 pow(x, n) ，即计算 x 的 n 次幂函数 */
/* 分治法,尾递归,O(logn) */
double powHelper(double x, int n, double re)
{
    if (n == 0)
        return 1 * re;
    else if (n == 1)
        return x * re;
    else
        return n % 2 == 0 ? powHelper(x * x, n / 2, re) : powHelper(x * x, n / 2, x * re);
}

double myPow(double x, int n)
{
    if (n < 0)
        x = 1 / x;
    return n % 2 == 0 ? powHelper(x * x, n / 2, 1) : powHelper(x * x, n / 2, x);
}
```
```Python []
class Solution:
    def myPow(self, x, n) -> float:
        if n < 0:
            x = 1 / x
        return self.myPowHelper(x * x, int(n / 2), 1) if n % 2 == 0 else self.myPowHelper(x * x, int(n / 2), x)
        
        
    def myPowHelper(self, x, n, re) -> float:
        if n == 0:
            return re
        elif n == 1:
            return x * re
        else:
            return self.myPowHelper(x * x, int(n / 2), re) if n % 2 == 0 else self.myPowHelper(x * x, int(n / 2), x * re)
```
```Java []
public class MyPow {
    public static double myPow(double x, int n) {
        if (n < 0) x = 1 / x;
        return n % 2 == 0 ? myPowHelper(x * x, n / 2, 1) : myPowHelper(x * x, n / 2, x);
    }


    private static double myPowHelper(double x, int n, double re) {
        if (n == 0) return re;
        else if (n == 1) return x * re;
        else return n % 2 == 0 ? myPowHelper(x * x, n / 2, re) : myPowHelper(x * x, n / 2, x * re);
    }
}
```


