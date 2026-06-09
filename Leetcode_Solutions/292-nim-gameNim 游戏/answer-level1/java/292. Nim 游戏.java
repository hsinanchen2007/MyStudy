/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/3
 * 
 * 解题思路: 保证让对手拿的都是4的倍数,这样最后一轮4个的时候，该对手拿，对手就输了
 * 
 */
![IMG_1752.JPG](https://pic.leetcode-cn.com/ec73dbff1a7033a6c72d4f7d07eb1d5e426808b8dae8d0de020ec06166858c49-IMG_1752.JPG)

```
public boolean canWinNim(int n) {
    if(n % 4 == 0){
        return false;
    }
    return true;
}
```