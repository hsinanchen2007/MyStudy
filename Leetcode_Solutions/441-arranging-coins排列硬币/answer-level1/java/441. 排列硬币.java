/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/11
 *
 * 解题思路1 : 暴力计算
 *
 * 解题思路2 : 多项式相加   n(n + 1)/2 =>  n*n + n = 2m => 解二次方程 => n = (-b + Sqrt(1 + 4*2*m))/2
 * 
 * 注意：long 类型防止溢出
 *
 */
```
 public int arrangeCoins(int n) {

        long o = 2*(long)n;

        for(long i = 0;i < Integer.MAX_VALUE;i++){
            if(i + i*i > o){
                return (int) i - 1;
            }else if(i + i*i == o){
                return (int) i;
            }
        }
        return -1;
    }

public int arrangeCoins2(int n) {
    return (int)((-1 + Math.sqrt(1 + 4*2*(long)n))/2);
}

```