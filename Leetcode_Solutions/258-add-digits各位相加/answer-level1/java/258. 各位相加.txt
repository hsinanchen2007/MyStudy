

/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/2
 *
 * 解题思路1：暴力解决
 * 解决思路2：n = abc = a*100 + b*10 + c*1   a + b + c = n - (99*a + 9*b)  = n % 9 (n%9!=0)
 */
```
public int addDigits(int num) {

        while(num >= 10){
            int mod = 0;
            int sum = 0;
            while(num != 0){
                mod = num % 10;
                sum += mod;
                num = num / 10;
            }
            num = sum;
        }
        return num;
    }

public int addDigits2(int num){

    if(num > 9){

        num = num % 9;
        if(num == 0){
            return 9;
        }
    }
    return num;

}
```