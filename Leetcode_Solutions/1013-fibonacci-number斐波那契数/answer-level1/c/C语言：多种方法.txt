方法1：通项公式

![fib.png](https://pic.leetcode-cn.com/5b9d2057fc8a1cbb57fdeb0cf9eaedce9425d522924b2ff45ea52941fa9c3fbd-fib.png)

```
int fib(int N){
    return 1 / sqrt(5.0) * (pow(0.5 * (1 + sqrt(5.0)), N) - pow(0.5 * (1 - sqrt(5.0)), N));
}
```

方法2：迭代法
```
int fib(int N){
    int a0 = 0, a1 = 1, an;
    
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;
    else{
        for (int i = 2; i <= N; i++){
            an = a0 + a1;
            a0 = a1;
            a1 = an;
        }
    }
    return an;
}
```
方法3：递归
```
int fib(int N){
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    return fib(N - 1) + fib(N - 2);
}

```


