参考官方的递归解释，官方算法存在一个问题，如果n是负数，先转换成小数，如果x是整数，可以先对x进行相乘，最后取倒数
```
public double myPow(double x, int n) {
    if (n == 0) return 1;

    boolean negativeFlag = n < 0;
    n = Math.abs(n);
    double result = fastPow(x,n);

    return negativeFlag ? 1 / result : result;
}

public double fastPow(double x, int n){
    if(n == 0) return 1;

    double half = fastPow(x,n/2);

    if(n % 2 == 0) return half * half;
    else return half * half * x;
}
```

