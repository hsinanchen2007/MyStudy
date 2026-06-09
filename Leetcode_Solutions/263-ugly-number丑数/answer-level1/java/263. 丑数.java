/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/9/2
 *
 * 解题思路：话不多说,连除判断质因子
 */
```
public boolean isUgly(int num) {

    if(num < 1){
        return false;
    }else if(num == 1){
        return true;
    }else {
        int mod = 0;
        int[] c = new int[]{2,3,5};
        int index = 0;
        while(num != 1){
            mod = num % c[index];
            if(mod != 0){
                index++;
            }else {
                num = num / c[index];
            }
            if(index > 2){
                return false;
            }
        }
        return true;
    }

}
```