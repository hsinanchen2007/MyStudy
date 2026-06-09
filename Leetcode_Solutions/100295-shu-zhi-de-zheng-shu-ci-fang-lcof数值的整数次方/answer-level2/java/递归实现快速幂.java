### 解题思路
第二种递归方法很巧妙，O（logn）

### 代码

```java
class Solution {
    /*这种方法会超时，因为pow(x, n/2)被算了两遍
    public double myPow(double x, int n) {
        //快速幂方法
        //当n为偶数，则x^n = x^(n/2) * x^(n/2)
        //当n为奇数，则x^n = x^(n/2) * x^(n/2) * x
        int exp = n > 0 ? n : (0-n);
        double res = pow(x, exp);
        return n > 0 ? res : 1 / res;
    }

    private double pow(double x, int n){
        if(n == 0){
            return 1;
        }
        if(n % 2 == 0){
            return pow(x, n/2)*pow(x, n/2);
        }
        return x*pow(x, n/2)*pow(x, n/2);
    }
    */
    public double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1 / x;
        double half = myPow(x, n / 2);
        double mod = myPow(x, n % 2);
        return half * half * mod;
    }
}



```