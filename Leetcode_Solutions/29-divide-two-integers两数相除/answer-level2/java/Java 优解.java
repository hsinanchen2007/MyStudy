这可能不是最简单的解法，但这是熟悉除法运算最底层实现的算法
曾经阿里的面试题便是：手写 “乘除法”，所以了解这些操作符底层的实现是很有必要的
```
public int divide(int dividend, int divisor) {
        //用long 来寄托传进来的值，省去很多判断int临界的情况
        long dd = dividend,dr = divisor;
        boolean flag = false;
        // 判断是否异号
        if ((dividend ^ divisor) < 0){
            flag = true;
        }
        //都变为正，之所以用long，也是在此处都转为正数时，如果是Integer.MIN_VALUE,转换后超过Integer.MAX_VALUE
        dd = dd >= 0 ? dd : -dd;
        dr = dr >= 0 ? dr : -dr;
        //此处存储结果值
        long res = 0;
        // 依次获取a的最高位
        long aux = 0;
        // 用来依次获取分母的最高位bit
        long mask = Integer.MAX_VALUE;
        mask++;
        while (mask != 0) {
            // 这里注意处理，尤其是后半部分表达式，很容易写成aux
            aux = (aux << 1) | ((dd & mask) == 0 ? 0 : 1);
            if (aux >= dr) {
                res = (res << 1) | 1;
                aux -= dr;
            } else {
                res = (res << 1) | 0;
            }
            mask >>= 1;
        }
        //如果结果值的负数为Integer.MIN_VALUE并且除数为-1表示的是 Integer.MIN_VALUE / -1 这一种情况，结果为Integer.MAX_VALUE
        //如果divisor == 1 结果可以是Integer.MIN_VALUE
        if(-res == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        return flag ? (int)-res : (int)res;
    }
```
注释比较详细，不懂可以评论