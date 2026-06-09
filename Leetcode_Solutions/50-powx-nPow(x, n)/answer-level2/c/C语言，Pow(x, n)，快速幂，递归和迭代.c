二分法经典应用`快速幂`

方法一：递归

```C
double myPow(double x, int n){
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n ==-1) return 1/x;
    double temp = myPow(x, n / 2);
    return temp * temp * myPow(x, n % 2);
}
```

方法二：迭代

```C
double myPow(double x, int n){
    double res = 1.0;
    if (n < 0) x = 1/x;
    while (n) {
        if (n & 1) res = res * x;   //括号内等同(n % 2)
        x = x * x;
        n = n / 2;
    }
    return res;
}
```
