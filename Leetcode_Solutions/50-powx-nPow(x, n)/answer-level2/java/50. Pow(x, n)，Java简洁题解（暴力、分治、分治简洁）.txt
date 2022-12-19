# 审题
1. x,n有取值范围，都是整数，会有复数
2. x^-n = 1/x^n

# 思路
1. 暴力
2. 分治

# 反馈
1. 牛顿迭代法
2. 复数可以最后用1/x解决 x^-n = 1/x^n

# 代码实现
1. 暴力法
2. 分治法
3. 分治法简洁版

## 1.暴力法

```java
/**
    * 暴力法 ps:这是比较原始的暴力法，可优化
    * 2775 ms	37.4 MB
    * @param x
    * @param n
    * @return
    */
private double directlySolution(double x, int n) {
    if (x == 1) {
        return x;
    }
    double ret = 1;

    // 对 int 型数据 -2147483648 求绝对值，结果仍为 -2147483648
    if (n <= -2147483648) {
        n = -2147483647;
        if (x < 0) {
            // -1.00000 -2147483648 预期结果 1.0
            return 1.0;
        }
    }
    for (int i = 0; i < Math.abs(n); i++) {
        if (ret == 0) {
            return ret;
        }
        ret = n >= 0 ? ret * x : ret / x;
    }
    return ret;
}
```

## 2.分治法

```java
/**
    * 分治法
    * 1 ms	36.8 MB
    * @param x
    * @param n
    * @return
    */
private double divideSolution(double x, int n) {
    if (n == 0) {
        return 1;
    }
    double v = divideGenerate(x, Math.abs((long) n));
    return n >= 0 ? v : 1 / v;
}

private double divideGenerate(double x, long n) {
    // 1 终止条件
    if (n < 2) {
        return x;
    }
    // 2 准备数据
    // 3 子问题
    double sub = divideGenerate(x, n / 2);
    // 4 合并
    // 5 清理
    if (n % 2 == 0) {
        return sub * sub;
    } else {
        return sub * sub * x;
    }
}
```

## 3.分治法简洁版

```java
/**
    * 分治法简洁版
    * 1 ms	36.5 MB
    *
    * @param x
    * @param n
    * @return
    */
private double divideCleanSolution(double x, long n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 1 / divideCleanSolution(x, -n);
    }
    return n % 2 == 1
            ? x * divideCleanSolution(x, n - 1)
            : divideCleanSolution(x * x, n / 2);
}
```