思想：被除数不断的减去除数达到除法的效果，减去的除数的个数即除法的结果；
为了避免计算过程中溢出，将输入的数据翻转到负数域进行计算（因为有符号数的负数域的容量比整数域的容量大1）；
为了更快的逼近结果，当一轮减法结束后剩下的值大于除数，下一次减去上次减的值的2倍（通过左移一位实现2倍放大）；

```java
// @lc code=start
class Solution {
    private static int dividend = Integer.MIN_VALUE;
    private static int divisor = 3;

    public static void main(String[] args) {
        Solution solution = new Solution();
        int res = solution.divide(dividend, divisor);
        System.out.println(res);
    }

    public int divide(int dividend, int divisor) {
        // 结果的正负
        boolean resIsNegitive = (dividend ^ divisor) < 0;

        // 将整数翻转到负数域，因为负数域比整数域的容量大1个数
        int dividendNeg = (dividend < 0 ? dividend : -dividend);
        int divisorNeg = (divisor < 0 ? divisor : -divisor);

        // 被除数小于除数，不够除
        if (divisorNeg < dividendNeg) {
            return 0;
        }

        int result = 0, toSub = divisorNeg, nexSub = divisorNeg, subresult = 1;
        int subRemain = dividendNeg;
        while (true) {
            int subRes = subRemain - toSub;

            if (subRes == 0) {
                // 减完后刚好等于0
                result += subresult;
                break;
            } else if (subRes > 0) {
                // 减完后结果大于0，减多了，从1个单位开始重新减
                nexSub = divisorNeg;
                toSub = nexSub;
                subresult = 1;
            } else if (subRes > divisorNeg) {
                // 剩下的不够减去一个除数了，结束
                result += subresult;
                break;
            } else if (subRes < divisorNeg) {
                // 减后还有很多，再减2倍的除数
                result += subresult;
                nexSub <<= 1;
                subresult <<= 1;
                toSub = nexSub;

                subRemain = subRes;
            } else if (subRes == divisorNeg) {
                // 减的只剩一个了，统计后退出
                result += subresult;
                result++;
                break;
            }
        }

        if (!resIsNegitive && result < 0) {
            // 不该出现结果的情况下result为负，只有可能是溢出了,减一就是Integer.MAX
            result = result - 1;
        }
        result = resIsNegitive ? -result : result;

        return result;
    }
}
```
