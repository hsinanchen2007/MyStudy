![image.png](https://pic.leetcode-cn.com/8dfc83136f997fc6400f7dc3f4c34a63c86ef4326a563f54a2377f14b71db3b5-image.png)

* 贪婪算法实现 空间和时间复杂度o(1)
* 1 2 3 是构成 n >= 4的基本组合 这里3的长度最大
* 所以我们尽可能将整数按照3拆分 这里我们定义 m = n / 3, x = n - 3m 其实也是余数(x = n % 3) 我们看下x的值情况如下
* 1. x == 0 product = 3^m * 1
* 2. x == 1 这种情况说明 (m - 1) * 3 + 4 = n 但是4不应该被分成1和3 应该分成 2 + 2 这里乘积 3^(m-1) * 2^2最大
* 3. x == 2 乘积为 3^m * 2
* 综上：我们最大乘积计算其实就是计算 3^m * 2^i 也就是说我们只需要3的指数个数和2的指数个数

```
int integerBreak(int n){
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;

    int cnt_3 = n / 3;
    int mod = n % 3;
    int cnt_2 = mod / 2;
    if (1 == mod) {
        cnt_3 -= 1;
        cnt_2 = 2;  // 这种情况为 4/2
    }
    // cnt_2如果不用余数计算可以在这里这么写
    // int cnt_2 = (n - cnt_3 * 3) / 2;

    return pow(3,cnt_3) * pow(2, cnt_2);
}
```
