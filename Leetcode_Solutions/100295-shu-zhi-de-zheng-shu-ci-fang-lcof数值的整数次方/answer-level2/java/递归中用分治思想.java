### 解题思路
注意，num取负向最小数，转为正数会溢出，所以转为long类型最为稳妥。

### 代码

```java
class Solution {
    public double myPow(double x, int num) {
        long n = (long)num;//转化成long，避免取正溢出
        //n可以为负数
        if(n == 0 || x == 1){
            return 1.0;
        }
        //n为负数时，改变入参
        if(n < 0){
            n = -n;
            x = 1/x;
        }
        return Pow(x,n);
    }
    private double Pow(double x, long n){
        if(n == 1){
            return x;
        }
        //double res = Pow(x,n/2);
        //分奇数和偶数讨论(分治思想)
        if(n % 2 == 0){
            return Pow(x*x,n/2);
            //return res * res;
        }
        return Pow(x,n-1)*x;
        //return res * res*x;
    }
}
```