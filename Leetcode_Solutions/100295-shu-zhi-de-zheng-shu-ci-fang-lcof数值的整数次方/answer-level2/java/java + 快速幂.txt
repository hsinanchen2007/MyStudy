### 解题思路
1.当x=0且n<=0时无意义，故做特殊处理
2.n为有符号数，最小值取负数时会越界，故扩大数据范围为long
3.如果直接用循环累乘：
```
while(count>0){
    res = res * x;
    count--;
}
```
显示提交超时
4.换快速幂成功提交
```
    while(count != 0){
            if((count & 1) == 1){
                res = res * x;
            }
            count = count >> 1;
            x = x * x;
    }
```
问题关键在于，指数的二进制表示，有1的位，所处在的位数转化为底数的累乘。


### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        // 当x<0 n<=0时无意义
        if(x==0 && n<=0){
            return 0;
        }
        
        long count = n;
        boolean isNeg = false;

        //n为负数时取得正可能越界，故扩大范围
        if(count < 0 ){
            isNeg = true;
            count = -1 * count;
        }
        double res = 1;
        while(count != 0){
            if((count & 1) == 1){
                res = res * x;
            }
            count = count >> 1;
            x = x * x;
        }
        
        return isNeg ? 1 / res : res;

    }
}
```