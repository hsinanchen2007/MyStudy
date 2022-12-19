### 解题思路
**我的小学老师说过：乘法就是相同加法的累加。无脑莽就完了，奥力给！**
思路：假如是6/2，除法是在表示6中含有几个2？那我直接用2加加加...一共加了多少次我一算不就完事了吗？这就是思路。
**首先进行几项特殊判断**
1.被除数是0
2.结果溢出判断
3.负数反转。这可能溢出，所以我使用了long，事实上long在里面占8个字节，所以严格来说，这样做不对。
**如果你真的这么做了，那么逻辑上是对的，但会超时。可以这样解决**
1.比如INT_MAX/1，那么这个数字会很大。所以我们在自增的时候，可以把步长拉大。比如进行指数级的增长。
2.但是聪明如你，指数级的自增，可能在某一步之后会越过那个恰好是结果的“点”。此时我们在进行步长为1的自减，就可以保证在指数级增长的前提下，还能保证结果是准确的。




### 代码

```c
int divide(int dividend, int divisor){
    long cnt = 0;
    int tag = 1;

    if (dividend == 0)
    {
        return 0;
    }

    /*符号判断*/
    if ((dividend < 0 && divisor >0) || (dividend > 0 && divisor < 0))
    {
        tag = -1;

    }
    /*结果溢出判断*/
    if (dividend <= INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    if (dividend == INT_MIN && divisor == 1)
    {
        return INT_MIN;
    }
    /*防止反转溢出*/
    long dend = dividend;
    long dor  = divisor;
    if (dividend < 0)
    {
        dend = -dend;
    }
    if (divisor < 0)
    {
        dor = -dor;
    }

    /*指数增长*/
    while (dor*(cnt+1) <= dend)
    {
        cnt = (2*cnt +1);
    }
    /*回退*/
    while (dor*cnt > dend)
    {
        cnt--;
    }

    return cnt*tag;

}
```