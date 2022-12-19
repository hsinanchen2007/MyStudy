我们只需要理解xn = x（n/2） * x((n+1)/2),此题就迎刃而解了，可以使用递归或者for循环，其中递归一定要避免二次递归的问题
（事实上调用Math里面的pow函数此题也过），递归方法代码如下
```
public static double myPow(double x, int n) {
        //处理幂的符号，统一为正数计算
        int signal = 1;
        if(n < 0){
            signal = -1;
            n = -n;
        }
        return signal > 0? pow(x,n): 1/pow(x,n);
        
    }
    private static double pow(double x, int n){
        if(n == 1)
            return x;
        if(n == 0)
            return 1;
        double halfAns = pow(x,n/2);
        return n%2 == 0 ? halfAns*halfAns : halfAns * halfAns * x;
    }
```

Java一行，哈哈哈，速度和空间基本差不多
```
public double myPow(double x, int n) {
        return Math.pow(x,n);
    }
```


