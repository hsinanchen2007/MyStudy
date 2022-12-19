### 解题思路
处理正负号后，直接递归把n个x相乘复杂度为O(n)，超时了；
若n=2k，则结果为(x^k)^2; 若n=2k+1，则结果为x*[(x^k)^2]; 如此可让n的值每次减半，复杂度O(logn)。

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        if(n < 0){
            x = 1 / x;
            n = (-1) * n;
        }
        return recurse(x, n);
    }

    public double recurse(double x, int n){
        if(n == 0) return 1;
        if(n == 1) return x;

        double res = recurse(x, n / 2);
        if(n % 2 == 0) res *= res;
        else res *= (res * x);

        return res;
    }
}
```