在不借助额外的存储结构的情况下，我们可以使用数学的方式进行反转（输入值 `x`）：

* 第一步，执行 `x%10` 可以得到 `x` 的最后一位数字，这也是我们所得结果的第一位数字
* 第二步，执行 `x = x/10`，由于 `x` 自身是 `int` 类型，运算完成之后，实际上等同于将 `x` 的最后一位舍弃
* 第三步，执行 `result = result * 10 + pop` 就可以将每一位的数字进行反转

由于需要考虑超出 32 位时溢出的情况，那么，`result = result * 10 + pop` 在什么情况下溢出呢？`result` 为正值的情况下，如果 `result` 大于 `Integer.MAX_VALUE / 10`，那么就一定会溢出，如果 `result` 等于 `Integer.MAX_VALUE / 10`，那么，`pop` 如果大于 `Integer.MAX_VALUE % 10` 也会产生溢出的情况。相反的，如果 `result` 为负值，也是一样的原理：

```java
public class Solution {
    public static int reverse(int x) {
        int result = 0;

        while (x != 0) {
            // x % 10 可以取到 x 最后一位的值，即此时 pop 是 x 的最后一位，也就是新值的第一位
            int pop = x % 10;
            // x 的位数少了最后一位
            x = x / 10;

            // 由于后续运算 result = result * 10 + pop
            // 如果 result 的值大于 Integer.MAX_VALUE / 10 ，那么一定会溢出
            // 如果 result 的值等于 Integer.MAX_VALUE / 10，那么 pop 的值如果大于 Integer.MAX_VALUE % 10 也会溢出
            // 相反的，result 的值小于 Integer.MIN_VALUE / 10 ，那么一定会溢出
            // 如果 result 的值等于 Integer.MIN_VALUE / 10，那么 pop 的值如果小于于 Integer.MIN_VALUE % 10 也会溢出

            if (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && pop > Integer.MAX_VALUE % 10)) {
                result = 0;
                return result;
            } else if (result < Integer.MIN_VALUE / 10 || (result == Integer.MIN_VALUE / 10 && pop < Integer.MIN_VALUE % 10)) {
                result = 0;
                return result;
            }

            result = result * 10 + pop;
        }
        return result;
    }

    public static void main(String[] args) {
        int target = 7654321;

        int result = reverse(target);

        System.out.println(result);
    }
}
```
