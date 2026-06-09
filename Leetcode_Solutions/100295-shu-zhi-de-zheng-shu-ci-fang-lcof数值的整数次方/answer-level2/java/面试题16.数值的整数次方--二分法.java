### 解题思路
利用二分法求解n次幂
1. 退出条件为n==1
2. 如果n为负数，返回结果为x*x^[(n-1)]/2*x^[(n-1)]/2;否则返回x^(n/2)*x^(n/2)

注意条件：
1. 当n为-2147483648时，取n的绝对值会溢出，应该先用一个long变量来保存n；
2. 求绝对值时应该加上long进行类型转换，long times = Math.abs((long)n)，否则Math.abs(n)返回的是与n同类型的值；
3. 利用变量存储double tmp = myPow(x, (int) (times / 2))，可以减少递归深度，否则会超出时间限制。
### 代码

```java
class Solution {
    //    二分求解幂
    public double myPow(double x, int n) {
//        处理边界和特殊情况
        if (n == 0) return 1;
        if (n == 1) return x;
        if (x == 1.0) return 1;

        boolean isNegative = (n > 0) ? false : true;
        long times = Math.abs((long)n);
        int rem = 0;
//        如果是奇数次方，则先把指数减掉1，变成偶数次方
        if (times % 2 == 1) {
            times = times - 1;
            rem = 1;
        }

        double tmp = myPow(x, (int) (times / 2));

        if (isNegative) return 1/(tmp * tmp * myPow(x, rem));
        return tmp * tmp * myPow(x, rem);
    }
}
```