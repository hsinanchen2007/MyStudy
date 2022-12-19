# 思想

有 $x = 3, n = 9, 20$

> x = 3, n = 9, 求 $3^9$

$9 = (1001)_2 = 2^3 + 2^0 = 8 + 1$
$x^n = 3^9 = 3^{2^3+2^0}= ((3^2)^2)^2 \cdot 3$

|3|2|1|0|
|:-:|:-:|:-:|:-:|
|1|0|0|1|
|res=res*x=$3*81$;|x=$x^2=81^2$|x = $x^2$= $9^2$|res *= x = $1\cdot3$; x = $x^2$ = $3^2$


> x = 3, n = 20, 求 $3^20$

$20 = (10100)_2 = 2^4 + 2^2$
$x^n = 3^20 = 3^{2^4 + 2^2} = (((3^2)^2)^2)^2 \cdot (3^2)^2$

# 代码

```java
class Solution {
    public double myPow(double x, int n) {
        double res = 1;
        long N = Math.abs((long)n);
        while(N > 0){
            if((N & 1) == 1) res *= x;
            N >>= 1;
            x *= x;
        }
        return n < 0 ?  1/res : res;
    }
}
```
