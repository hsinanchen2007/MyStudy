参考了国际版leetcode的讨论区解法

核心思想：由大到小构造一个回文数，然后看这个回文数是否能由给定的数相乘得到。

- 第一个循环为什么从max - 1开始？
    9x9 = 81
    99x99 = 9801
    999x999 = 998001
    9999x9999 = 9980001
    etc.
    可以看出， max * max 得到的数一定不是回文数，所以从max - 1开始循环
- 如何判断构造的回文数能够由给定的数相乘得到？
    看回文数能否被给定的数之一整除
- 举个例子：
    max = 99;
    从i= 98开始循环
    构造出回文数 rev = 9889
    对于 x = 99 ，rev不能整除，继续
    对于 x = 98 , 98 * 98 = 9604,小于rev，退出第二层循环
    ...
    ...
    直到i= 90
    构造出回文数9009
    对于x = 99 ， 整除，得到结果

```
class Solution {
    public int largestPalindrome(int n) {
        if(n == 1) return 9;
        //计算给定位数的最大值
        long max = (long)Math.pow(10,n) - 1;
        //从max - 1开始循环，原因见上文
        for(long i = max - 1; i > max / 10; i--){
            //1. 构造回文数
            String s1 = String.valueOf(i);
            long rev = Long.parseLong(s1 + new StringBuilder(s1).reverse().toString());
            //2. 检验该回文数能否由给定的数相乘得到
            for(long x = max; x * x >= rev; x --){
                if(rev % x == 0) return (int)(rev % 1337);
            }
        }
        return -1;
    }
}
```
