### 解题思路
因为我的菜，把这题想的很简单，以为只需要靠减法就可以，但对于-2^32~2^32-1这个范围内的数，如果数很大的话则我写的减法完全超出了时间限制，1028ms我也是醉了，一时没想起来位运算，不过也好通过这道题，我对除法转化成位运算有了进一步的了解，至于代码，是在网上借鉴某位大佬的，希望以后多做做这种题目来提高自己的编程思想吧！

### 代码

```c
int divide(int dividend, int divisor){
    int INTMAX = 2147483647;
    int INTMIN = -2147483648;
    long long remain=0;
    int sign;
    if((dividend>0&&divisor>0)||(dividend<0&&divisor<0))
    {
        sign=1;
    }
    if((dividend<0&&divisor>0)||(dividend>0&&divisor<0))
    {
        sign=-1;
    }
    if(divisor==1)
    {
        return dividend;
    }
    if(dividend==INTMIN&&divisor==-1)
    {
        return INTMAX;
    }
    if(dividend==0&&divisor!=0)
    {
        return 0;
    }
    if(divisor==0)
    {
        return INTMAX;
    }
    long long dividen=llabs((long long)dividend);
    long long diviso=llabs((long long)divisor);
    while(dividen>=diviso)
    {
        long long t=diviso,p=1;
        while(dividen>=(t<<1))//左移一位相当于乘了2倍，所以是用位运算代替了除法，每次商都乘2
        {
            t=t<<1;//相当于是t乘了2
            p=p<<1;//相当于是p乘了2
        }
        remain=remain+p;
        dividen=dividen-t;
    }
    return sign==1?remain:-remain;
}


    /*if(dividend==INTMIN&&divisor==-1)
    {
        return INTMAX;
    }
    if(dividend==0&&divisor!=0)
    {
        return 0;
    }
    if(divisor==0)
    {
        return INTMAX;
    }
    long long dividen=(long long)dividend;
    long long diviso=(long long)divisor;
    if(dividen>0&&diviso>0)
    {
        remain=dividen;
        while(remain>=diviso)
        {
            remain-=diviso;
            count1++;
        }
    }
    else if(dividen<0||diviso<0)
    {
        if(dividen<0&&diviso>0)
        {
            remain=-dividen;
            while(remain>=diviso)
            {
                remain-=diviso;
                count2--;
            }
        }
        else if(dividen>0&&diviso<0)
        {
            diviso=-diviso;
            remain=dividen;
            while(remain>=diviso)
            {
                remain-=diviso;
                count3--;
            }
        }
        else
        {
            dividen=-dividen;
            diviso=-diviso;
            remain=dividen;
            while(remain>=diviso)
            {
                remain-=diviso;
                count4++;
            }
        }
    }*/
```