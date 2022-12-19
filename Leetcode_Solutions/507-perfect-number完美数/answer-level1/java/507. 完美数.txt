/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/22
 *
 * 解题思路: 很简单 求因子的时候记得 sqrt 就行
 *
 */
```
public boolean checkPerfectNumber(int num) {
    if(num == 1){
        return false;
    }
    int sum = 1;
    for(int i = 2;i <= Math.sqrt(num);i++){
        if(num %i == 0){
            sum += i;
            sum += num / i;
        }
    }
    if(sum == num){
        return true;
    }
    return false;
}
```