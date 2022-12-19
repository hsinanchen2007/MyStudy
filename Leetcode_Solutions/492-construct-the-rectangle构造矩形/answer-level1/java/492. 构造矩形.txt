/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/18
 *
 * 解题思路1：直接暴力除 直到两个因子的差最小
 *
 * 解题思路2：使用开根号的思想 一个数的平方根是他的最小差"因子" 因此 想要获取最小整数因子 就需要对开根号后的数据进行--处理 直到能被整除
 *
 */

```
//时间比较长
public int[] constructRectangle(int area) {

    int d = area - 1;
    int res[] = new int[]{1,1};
    for(int i = area - 1 ;i >=2;i--){
        int t = Math.abs(i - (area % i));
        if(area % i == 0 && Math.abs(i - (area / i)) < d){
            res[1] = area / i;
            res[0] = i;
            d = Math.abs(i - res[1]);
        }else if(Math.abs(i - area / i) >= d){
            break;
        }

    }
    return res;

}

public int[] constructRectangle2(int area) {

    int sqrt = (int)Math.sqrt(area);
    while(area % sqrt != 0)sqrt--;
    return new int[]{area/sqrt,sqrt};

}
```