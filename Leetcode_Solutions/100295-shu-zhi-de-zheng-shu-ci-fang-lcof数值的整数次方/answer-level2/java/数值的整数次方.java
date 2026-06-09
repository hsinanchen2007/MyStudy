**题解：**
数值的整数次方，注意判断一下 幂次为奇数还是偶数的情况，同时还有n为正负时也是需要考虑一下；
```java
class Solution {
    public double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(n==1) return x;
        double half = myPow(x,n/2);
        if(n>0){
            if(n%2==0){
                return half*half;
            }else{
                return x*half*half;
            }
        }else{
            n = -n;
            x = 1/x;
            if(n%2==0){
                return half*half;
            }else{
                return x*half*half;
            }
        }
    }
}
```
