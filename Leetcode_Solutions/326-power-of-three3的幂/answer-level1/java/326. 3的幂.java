/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/3
 *
 *
 * 解题思路1: log10^n / log10^3 = log3^n  看有没有小数位
 *
 * 解题思路2: Math.max 是int最大值,求出这个范围内3的最高幂（因子全是质因子3）后，对当前数取余数，来看是否是为3的幂
 *
 */
```
public boolean isPowerOfThree(int n) {

    //第一种
    //return Math.log10(n)/Math.log10(3)%1 == 0;

    //第二种
    return n > 0 && 1162261467%n == 0;
}
```