解题思路：题目简化分析：返回一个由数字从小到大拼接的字符串中指定索引字符
1、不要尝试拼接字符串，太消耗性能，通过数字规律算法找到满足索引n的最后一个数字，并需要得知此数字的位数
// 0 - 9        个位数
// 10 - 99      两位数
// 100 - 999    三位数

2、找到最后一个数字后，当前字符串的长度一定 > n ，因为n是索引，注意第一次字符 0

// 参考代码如下: 我比较笨拙分析了很久，大神绕过

```
public int findNthDigit(int n) {
    if (n == 0) return n;
    // pre : 上一位数的字符串长度
    // size : 当前位数的字符串长度
    long pre, size = 0;
    for (long i = 1; i < n; i++) {
        pre = size;
        long last = 0;
        for (long k = i; k > 0; k--) {
            last += Math.pow(10, k - 1);
        }
        last = 9*last;
        long start = i == 1 ? 0 : new Double(Math.pow(10, i-1)).longValue();
        size  += i == 1 ? i * (last - start) + 1 : i * (last - start + 1);
        // 索引n落在当前位数的字符串内, size一定会大于 索引 n
        if (size > n) {
            // 到数字p时, 结束
            long p = start + (n - pre)/i;
            // 加上数字p的位数后, 字符串总长度 pre 上一次位数的数字总长度 + i *
            long l = pre + (p - start + 1) * i;
            String number = String.valueOf(p);
            // 长度l - n 一定大于0 , 否则找到的数字不准确, 因为第一个数字是0 当 n = 3 时, 长度是 4
            // 数字的长度 number.length() 数字超过的长度 l - n
            // 数字p拼接的最后一个数字
            if (l - n == 1) {
                return (number.charAt(number.length() - 1) - '0');
            }
            char end = number.substring(number.length() - new Long(l - n).intValue()).charAt(0);
            int res = end - '0';
            return res;
        }
    }
    return 1;
}
```
