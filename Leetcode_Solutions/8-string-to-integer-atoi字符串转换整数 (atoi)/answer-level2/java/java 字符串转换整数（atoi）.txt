思路：

去掉前导空格；
再是处理正负号；
识别数字，注意越界情况。

这道题目如果只是简单地字符串转整数的话，就是简单地 ans = ans * 10 + digit。
但是注意这道题目可能会超过integer的最大表示！
也就是说会在某一步 ans * 10 + digit > Integer.MAX_VALUE。
*10 和 +digit 都有可能越界，那么只要把这些都移到右边去就可以了。
ans > (Integer.MAX_VALUE - digit) / 10 就是越界。