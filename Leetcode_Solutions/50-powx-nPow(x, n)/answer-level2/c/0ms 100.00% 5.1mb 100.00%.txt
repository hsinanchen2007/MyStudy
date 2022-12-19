### 解题思路
改来改去我也不知道自己写的是什么
大概思路就是
例如100=64+32+4
那么我们计算2的100次幂就只需要算2^64+2^32+2^4
而只要指数是2的若干次幂
则可通过若干次自乘很快得到
主要是我基本功太差改来改去最后也看不懂自己写得是什么
指数为0和1的特殊情况就特殊处理了

### 代码

```c

double myPow(double x, long n){
    if(n==0){
        return 1;
    }
    if(n<0){
        x=1/x;
    }
    n=n>0?n:-n;
    if(n==1){
        return x;
    }
    double temp=x,res=1;
    long i=1;
    int flag=0;
    do{
        if(n==1){
            flag=1;
            temp=x;
            res*=temp;
            break;
        }else if(i*2<n){
            flag=0;
            temp*=temp;
            i*=2;
        }else{
            flag=1;
            res*=temp;
            n-=i;
            i=1;
            temp=x;
        }
    }while(i<n);
    res*=x;
    return res;
}
```