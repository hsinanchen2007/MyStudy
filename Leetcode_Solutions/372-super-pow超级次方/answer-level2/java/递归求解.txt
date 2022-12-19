# 思路
1. ten_power 存储a^(10*(length-1-i))%1337的值以便后续计算。
2. 对于b[i]处的求解，根据(a^ten_power)^b[i]，从后往前逐个计算b数组中的次方.

# 代码
```
public int binaryPow(int a, int n) {
    if (n == 0) {
        return 1;
    }
    int h = binaryPow(a, n / 2);
    if (n % 2 == 0) {
        return (h * h) % 1337;
    } else {
        // 此处务必两次mod，因为h*h*a的话，以最坏情况1336^3计算，是会超过Integer.MAX_VALUE的
        return ((h * h) % 1337) * a % 1337;
    }
}

public int superPow(int a, int[] b) {
    int rst = 1;
    int ten_power = 0, len = b.length, i_power = 0;
    if (a == 1) {
        return a;
    }
    a = a % 1337;
    ten_power = a;

    for (int i = b.length - 1; i >= 0; i--) {
        i_power = binaryPow(ten_power, b[i]);
        rst = (rst * i_power) % 1337;
        ten_power = binaryPow(ten_power, 10);
    }
    return rst;
}
```
# 总结
- 时间复杂度O(mlogn)： m为b.length,n为b[i]中的最大值；
- 空间复杂度O(logn): 对于每个b[i] (=n),计算O(logn)次,每次计算，需要存储a^(n/2)的结果。 