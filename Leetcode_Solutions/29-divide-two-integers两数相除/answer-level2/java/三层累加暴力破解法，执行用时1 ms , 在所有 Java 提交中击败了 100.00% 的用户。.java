### 解题思路
本质就是返回被除数能被除数分成多少份的个数。
然而被除数太大且除数太小循环时间必然过长，所以采用了三层累加的算法大大降低了循环次数。
### 代码

```java
class Solution {
    public int divide(int dividend, int divisor) {
       if(dividend==Integer.MIN_VALUE&&divisor==-1)
            return Integer.MAX_VALUE;
        int sum=0;
        int t=0;//累加数
        int sums=0;
        int ts=0;//累加数的累加数
        int tmp=0;
        int b=0;//被除数应减除数的倍数和i应加数
        int i=0;
        int flat=(dividend^divisor);//结果正负标志位
        dividend=(dividend<0)?dividend:-dividend;//被除数取负值
        divisor=(divisor<0)?divisor:-divisor;//除数取负值
       while(dividend<=divisor){//暴力累加法
            sum+=divisor;
            t++;
            sums+=sum;
            ts+=t;
            tmp+=sums;
            b+=ts;
           if(dividend-tmp<0&&tmp<0){//判断三层累加是否超出
                i+=b;
                dividend-=tmp;
           }else{//超出则普通累加
                i++;
                dividend-=divisor;
                sum=0;
                t=0;
                sums=0;
                ts=0;
                tmp=0;
                b=0;
           }
       }
       return(flat<0)?-i:i;
    }
}
```