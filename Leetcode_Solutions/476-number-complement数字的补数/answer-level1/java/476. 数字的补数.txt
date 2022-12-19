/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/18
 *
 * 解题思路: 位运算 取最低位乘上进制 求和
 */

```
public int findComplement(int num) {

    int res = 0;
    int j = 1;
    while(num != 0){
        res += j*((num & 1)^ 1);
        j *=2;
        num >>=1;
    }
    return res;
}
```