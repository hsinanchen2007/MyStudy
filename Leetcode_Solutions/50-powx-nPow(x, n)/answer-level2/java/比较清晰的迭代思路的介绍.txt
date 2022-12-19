## 题解思路
看官方的中文题解有点没看懂，解释的比较晦涩，看到国外论坛的迭代思路的介绍：https://leetcode.com/problems/powx-n/discuss/19563/Iterative-Log(N)-solution-with-Clear-Explanation
这个比较清晰，用中文解释一下。
思路就是对n看做二进制数组，比如9可以看做1001，x的9次方就可以x^8 * x^1（分别对应二进制中的第3位和第0位的1），所以迭代对象就是对这个
二进制进行迭代，N & 1 表示迭代的时候碰到了1，表示需要把当前的乘数乘到result中。可以考虑这是对这个二进制数组从后向前遍历，数组每个
位置表示一个乘数，乘数就是x的n次方，这个n就是2^(位置)。在遍历的过程中，需要记录乘数，记为currentProduct，currentProduct每次在右移一位
二进制的时候，currentProduct的值就会进行相乘，currentProduct  = currentProduct * currentProduct;

## 执行结果
![image.png](https://pic.leetcode-cn.com/2189eaa861e3427783083222e249e369ed276957d26c00616c4062d6550922e7-image.png)

## 代码
### 栈代码：
```

/**
 * @author michael
 * @Description: 迭代思路的介绍：https://leetcode.com/problems/powx-n/discuss/19563/Iterative-Log(N)-solution-with-Clear-Explanation
 * 这个比中文的题解介绍的清晰
 * 思路就是对n看做二进制数组，比如9可以看做1001，x的9次方就可以x^8 * x^1（分别对应二进制中的第3位和第0位的1），所以迭代对象就是
 * 对这个二进制进行迭代，N & 1 表示迭代的时候碰到了1，表示需要把当前的乘数乘到result中。可以考虑这是对这个二进制数组从后向前遍历，数组每个
 * 位置表示一个乘数，乘数就是x的n次方，这个n就是2^(位置)。在遍历的过程中，需要记录乘数，记为currentProduct，currentProduct每次在右移一位
 * 二进制的时候，currentProduct的值就会进行相乘，currentProduct  = currentProduct * currentProduct;
 * For example, lets say
 *
 * N = 9 = 2^3 + 2^0 = 1001 in binary. Then:
 *
 * x^9 = x^(2^3) * x^(2^0)
 *
 * We can see that every time we encounter a 1 in the binary representation of N, we need to multiply the answer
 * with x^(2^i) where i is the ith bit of the exponent. Thus, we can keep a running total of repeatedly
 * squaring x - (x, x^2, x^4, x^8, etc) and multiply it by the answer when we see a 1.
 *
 * To handle the case where N=INTEGER_MIN we use a long (64-bit) variable
 * @date 2020/2/4 5:42 PM
 */
class Solution {
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double result = 1;
        double currentProduct = x;
        long N = n;
        if (n < 0) {
            /**
             * 注意这里一定要用N = -N来取反，因为这里n存在溢出的问题，n为MIN_VALUE的时候，所以一定需要转正long才能取反，
             * 如果写成N = -n取反会失败，因为n还是int，无法取反。
             */
            N = -N;
        }
        while (N > 0) {
            if ((N & 1) == 1) {
                result = result * currentProduct;
            }
            N >>= 1;
            currentProduct  = currentProduct * currentProduct;
        }
        return n > 0 ? result : 1/result;
    }
}
```