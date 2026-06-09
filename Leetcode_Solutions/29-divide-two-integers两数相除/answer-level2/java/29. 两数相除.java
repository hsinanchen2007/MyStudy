
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/20
 *
 *
 * 解题思路：20/3 ===  (3x2^2 + 3x2^1) 将 2^2 + 2^1 = 6 即为商的结果 然后将x2操作转化为位运算即可 理解:20可以看作总和 然后不断减去3的倍数(在过程中记录3的个数,也就是商)
 *
 * 知识点：位运算的一些知识1.Integer.MAX_VALUE 左移一位变成0  2.Integer.MIN_VALUE 左移一位变成-1 3.在计算机内部,负数存储的二进制数要解析出来必须取反+1 4. >> 和 << 移位包含符号位
 *
 */

```
public int divide(int dividend, int divisor){

    //判定商的符号
    boolean sign = (dividend > 0) ^ (divisor > 0);

    //将被除数和除数转化负数进行运算
    if(dividend > 0) dividend = - dividend;
    if(divisor > 0) divisor = - divisor;

    //进行循环求商
    int res = 0;
    while(dividend <= divisor){
        int temp_res = -1;
        int temp = divisor;
        while(dividend <= (temp << 1)){
            //如果移位出现负数越界
            if(temp < Integer.MIN_VALUE >> 1) break;
            temp = temp << 1;
            temp_res = temp_res << 1;
        }
        dividend -= temp;
        res += temp_res;
    }

    //当商是正数的时候的 进行取反操作
    if(sign == false){
        //防止正数越界 -2147483648 --> 2147483647(2147483648会越界)
        if(res <= Integer.MIN_VALUE) res = Integer.MAX_VALUE;
        else res = -res;
    }
    return res;
}
```