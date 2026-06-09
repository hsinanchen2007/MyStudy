1、首先想到的是用减法，看次数。不过如果被除数很大，除数很小，就会循环很多次影响性能。
于是写了一个递归，通过左移的方法，使除数快速逼近被除数。
2、注意正负号问题
3、这里最坑的地方在于-2147483648  取反后 还是-2147483648 ，所以我们可以先让他变成  -2147483647 再取反，之后我们再把那个1加回来即可

```
public int divide(int dividend, int divisor) {
        boolean symbol = false;
        boolean gap = false;
        if(divisor == 1)return dividend;
        if(dividend == divisor)return 1;
        if(dividend == -2147483648 && divisor == -1)return 2147483647;
        if(divisor == -2147483648)return 0;
        if(dividend == -2147483648){
            dividend++;
            gap = true;
        }
        if(divisor == -1)return -dividend;
        if(dividend <0){
            symbol = !symbol;
            dividend = -dividend;
        }
        if(divisor <0){
            symbol = !symbol;
            divisor = -divisor;
        }
        if(divisor > dividend) return 0;
        int times =0;
        if(gap){
            dividend = dividend - divisor +1;
            times = 1 + getTimes(dividend,divisor);
        }else{
            times = getTimes(dividend,divisor);
        }
        if(times <0 && !symbol)times--;
        return symbol?-times:times;
    }
    private int getTimes(int dividend, int divisor){
        if(dividend < divisor) return 0;
        if(dividend == divisor) return 1;
        int i=1;
        while (divisor << i >0 && divisor << i < dividend) {
            i++;
        }
        i--;
        return (1<<i) + getTimes(dividend - (divisor << i),divisor);
    }
```
