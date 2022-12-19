/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/29
 *
 * 解题思路: 位运算 n为2的指数就是说n的2进制只有一个1，n-1也只有一个1，n&(n-1) == 0 , 不然的话非0
 */
```
 public boolean isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n&(n-1)) == 0;
 }
```