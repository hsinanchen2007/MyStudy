使用求平方根的牛顿迭代公式来求解a的平方根
公式为：X[n+1]=(X[n]+a/X[n])/2 要求前后两次求出的差的绝对值少于0.00001。
即x=1,x1=(1+a/1)/2,要求|x-x1|<0.00001，此时x是求得的近似平方根
```
var mySqrt = function(x) {
    var num = 1,num1;
    //使用牛顿迭代函数
    do{
        num1 = num;
        num = (num1+x/num1)/2;
    }
    //使用Math.abs()求绝对值
    while(Math.abs(num-num1)>0.00001);
    //保留整数部分
    return parseInt(num);
    
};

```

