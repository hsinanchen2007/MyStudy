### 解题思路
要用到贝祖定理、辗转相除法
1、要想实现要求，则需使得方程ax+by=z有解，而根据贝祖定理可知
要使得方程有解，则必使得z为x,y的最大公约数的倍数，即可被除尽
2、由辗转相除法求最大公约数：
（1）若较大数能被较小数除尽，则较小数即为最大公约数
（2）若未能除尽，则将较小数作为较大数，将余数作为较小数
（3）不断重复上述两步骤，直到除尽，找到最大公约数。
### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (x+y<z)return false;

        if (x==0||y==0){
            return z==0||x+y==z;
        }

        return z%gcd(x,y)==0;
    }

    public int gcd(int m, int n){
        return m%n==0?n:gcd(n,m%n);
    }
}
```