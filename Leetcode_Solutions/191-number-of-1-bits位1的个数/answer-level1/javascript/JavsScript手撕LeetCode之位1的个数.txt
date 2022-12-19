
![稿定设计导出-20200322-163215.png](https://pic.leetcode-cn.com/7619091bfdedaf74ef5539dc1de4adeda761c8a1d4b03a249efb763869179fd7-%E7%A8%BF%E5%AE%9A%E8%AE%BE%E8%AE%A1%E5%AF%BC%E5%87%BA-20200322-163215.png)

当然在JavaScript中，也是没有无符号整数类型的，JavaScript的Number类型为双精度IEEE 754 64位浮点类型。所以这里我们的输入都是有符号整数类型。那么我们的问题就转换成了输入一个整数，返回其二进制表达式中数字位数为‘1’的个数

# 十进制转二进制
这里我们很容易想到，将数字处理成二进制，然后统计其1的个数。从十进制转成二进制，不断除以2，直到为0。

```

/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let count = 0;
    while (n) {
        count += n % 2; 
        n = n >> 1;
        // n = Math.floor(n / 2);
    }
    return count;
};
```

# 位运算
这是官方题解里面的解法

将输入的数字n与位掩码(初始值为1)的二进制做与运算，即可以得到n的最低位。举个例子

已知 0 & 1 = 0, 1 & 1 = 1

1的二进制表示是0000 0000 0000 0000 0000 0000 0000 0001
3的二进制表示是0000 0000 0000 0000 0000 0000 0000 0011

则 1 & 3，
结果二进制表示是0000 0000 0000 0000 0000 0000 0000 0001，即为1,得到了3的最低位。

检查下一位时，我们将掩码左移一位。

```
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let counts = 0;
    let mask = 1;
    for (let i = 0; i < 32; i++) {
        if ((n & mask) !== 0) {
            counts++;
        }
        mask <<= 1;
    }
    return counts;
};
```
# 位运算更简洁的做法
前面一种算法，需要检查数组的每一位。接下来的这种做法，不需要检查完每一位。而是通过不断的把数字的最后一个1进行反转。

核心思想是想法是对于任意数字 n ，将 n 和 n - 1 做与运算，会把最后一个 1 的位变成 0

```
n           ...1110100 // 倒数第3位是1
n - 1       ...1110011
n & (n -1)  ...1110000 // 倒数第3位为0
```

```
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let counts = 0;
    while(n) {
        counts++;
        n &= n - 1
    }
    return counts;
};
```

关注微信公众号【李一二】，看更多js算法题解。
添加微信sail19971026, 进入技术交流群。