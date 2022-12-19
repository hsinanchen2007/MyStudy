/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/11/13
 * 
 * 解题思路: 快速幂思想 
 * 如:2^10 -- (2^2)^5 = ((2^2)^4)*(2^2) = (((2^2)^2)^2)*(2^2)  = (偶数幂)*(奇数幂乘积)
 *    2^11 -- (((2^2)^2)^2)*((2^2)*2) = = (偶数幂)\*(奇数幂乘积)
 * 
 */
```
public class leetcode050 {

    public double myPow(double x, int n) {

        double res = 1;
        if(n < 0){
            x = 1 / x;
            n = -n;
        }
        return fastPow(x,n);
    }

    public double fastPow(double x , int n){
        double res = x;
        double temp = 1;
        if(n == 0){
            return 1;
        }
        while(n !=0 && n != 1){
            if(n % 2 == 1){
                //temp 用于记录奇数幂的乘积
                temp *= res;
            }
            res = res * res;
            n = n /2;
        }
        //补上奇数幂的乘积
        return res*temp;
    }

    public static void main(String[] args) {
        leetcode050 leetcode050 = new leetcode050();
        leetcode050.myPow(2 ,10);
    }
}
```