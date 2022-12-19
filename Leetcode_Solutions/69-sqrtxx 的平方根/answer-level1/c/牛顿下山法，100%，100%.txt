### 解题思路
牛顿下山法，为了防止程序陷入死循环，对循环次数进行计数

### 代码

```c
long sqr(long x);

int mySqrt(int x){
    if(x==1){return 1;}
    float result=50;//设置初值，比较随意
    int count=0;
    while(!(sqr((long)result)<=x&&sqr((long)result+1)>=x)){
        result=result-(sqr(result)-x)/(2*result);//牛顿下山法公式
        count++;
        if(count>=15){result--;count=0;}//防止程序陷入死循环
    }
    return (int)result;
}
long sqr(long x){
    return (long)(x*x);
}
```