/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/17
 *
 * 解题思路: 位运算 不多说了
 */

```
public int hammingDistance(int x, int y) {
    int z = x ^ y;

    int count = 0;
    while(z != 0){
        if((z&1) == 1){
            count ++;
        }
        z >>= 1;
    }
    return count;
}
```