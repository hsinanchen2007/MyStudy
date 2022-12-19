[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_50_myPow.java)

```java
    /**
     * 解析思路：
     * 平方不就是n个数相乘么，n为负数的时候，先将x求倒数，再n次相乘(此方法会提交超时O(n))
     * <p>
     * 优化：
     * 将上述循环相乘的方法根据分治思想，一分为二（只需要求一半即可，另一半是相同的，奇数再*x），不断拆分至两个数相乘，时间复杂度优化到O(LogN)
     * 这个方法称为"快速幂乘法"
     *
     * @param x
     * @param n
     * @return
     */
    public double myPow(double x, int n) {
        if (n < 0) {
            x = 1f / x;
        }
        n = Math.abs(n);
        //分治求解
        return fastPow(x, n);
    }

    double fastPow(double x, long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
```