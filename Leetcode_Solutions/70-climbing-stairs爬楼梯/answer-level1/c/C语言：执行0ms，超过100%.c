```
int climbStairs(int n){
    int a = 0, b = 1, c = 0;
    while (n--){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
```
```
//或者直接用斐波拉契数列通项公式(不过n = n + 1)
int climbStairs(int n){
    return 1 / sqrt(5.0) * (pow(0.5 * (1 + sqrt(5.0)), n + 1) - pow(0.5 * (1 - sqrt(5.0)), n + 1));
}
```

