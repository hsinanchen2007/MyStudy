思路可以参考其他大佬的，主要是对long类型改进为int类型，符合题目条件。
首先，我们把两个数准换为负数，这样就不会产生使用Math.abs()函数导致的溢出问题。
然后在返回值res（最后结果）和自增变量tmp（每次对除数倍数增长）中添加溢出条件判断。


```Java[]
public int divide(int dividend, int divisor) {
        //把两个数都转为负数
        int sign = 1;
        if (dividend > 0) {
            dividend =  -dividend;
            sign = -sign;
        }
        if (divisor > 0) {
           divisor = -divisor;
           sign = -sign;
        }
        //排除除数数字0
        if (dividend == 0) {
            return 0;
        }
        int res = 0;
        int dividendTmp = dividend;
        int divisorTmp = divisor;
        while (dividendTmp <= divisorTmp) {
            int tmp = divisorTmp;
            int i = 1;
            while (dividendTmp <= tmp) {
                dividendTmp -= tmp;
                //防止溢出
                if(res  > Integer.MAX_VALUE - i ){
                    return sign==1?Integer.MAX_VALUE:Integer.MIN_VALUE;
                }
                res += i;
                //防止溢出
                if(Integer.MIN_VALUE - tmp < tmp){
                    tmp <<=1;
                    i<<=1;
                }
            }
        }
        return sign==1?res:-res;
    }
```

