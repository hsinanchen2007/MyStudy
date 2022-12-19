/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/8
 *
 * 解题思路: 位运算 不多说了
 *
 */
```
public boolean hasAlternatingBits(int n) {
    boolean res = true;
    int pre = -1;
    while(n != 0){

        if(pre != -1 && pre == (n & 1)){
            res = false;
            break;
        }else{
            pre = n & 1;
            n = n >> 1;
        }

    }

    return res;
}
```
