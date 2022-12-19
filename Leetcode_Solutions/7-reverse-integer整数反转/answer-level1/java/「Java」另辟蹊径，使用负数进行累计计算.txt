```java
/**
 *
 * 整数正数最大值为 2147483647
 * 整数负数最小值为 -2147483648
 *
 * 最大值的负数比正数多表示一位数（因为原码->反码的转换过程，-0 会替换为多出来的最小负数）
 *
 * 计算过程分析：
 * 所以过程计算中我们「采用负数」继续累计计算，只要在负数范围没有溢出最终转换为正数时也是不会溢出的，因为 -MAX_VALUE > MIN_VALUE
 *
 * 情况 1 : 如果当前为正数，我们一直做减操作转换为负数，溢出条件为 -MAX_VALUE
 * 情况 1 : 如果当前为负数，我们保留符号位后按正数计算，我们一直做减操作转换为负数，溢出条件为 MIN_VALUE
 *
 * 溢出情况分析：
 * 情况 1：ans = ans * 10; 乘法溢出，只要不超过 阈值/10
 * 情况 2：ans -= pop; 加法溢出，只要不超过 阈值 + pop（阈值为负数）
 *
 * 最终结果：
 * 最终我们通过符号位，如果为负数 ? 负数 : -负数
 *
 * 该类型题 _7_整数反转、_8_字符串转整数
 */
public int reverse(int x) {
    boolean negative = x < 0; // 是否为负数
    int limit = negative ? Integer.MIN_VALUE : -Integer.MAX_VALUE;
    int min = limit / 10;

    x = Math.abs(x); // x 转换为正数进行逐个反转

    int ans = 0;
    while (x != 0) {
        int pop = x % 10;
        if (ans < min) { // 乘法溢出判断
            return 0;
        }
        ans = ans * 10;
        if (ans < limit + pop) { // 加法溢出判断
            return 0;
        }
        ans -= pop;
        x = x / 10;
    }
    return negative ? ans : -ans;
}
```