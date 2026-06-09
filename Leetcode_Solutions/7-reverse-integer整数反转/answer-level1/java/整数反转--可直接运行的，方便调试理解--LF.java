```
package ZJM_7_整数反转;

public class Main {
    public static void main(String[] args) {
        int num1 = 123;
        int num2 = -123;
        int num3 = 120;
        int num4 = 1534236469;

        Solution solution = new Solution();
        System.out.println(solution.reverse(num1));
        System.out.println(solution.reverse(num2));
        System.out.println(solution.reverse(num3));
        System.out.println(solution.reverse(num4));
    }
}

class Solution {
    public int reverse(int x) {
        int temp = 0;

        while (x % 10 != 0 || x / 10 != 0) {
            if (temp < -214748364 || temp > 214748364) {
                return 0;
            }
            temp *= 10;

            temp += x % 10;
            x /= 10;
        }

        return temp;
    }
}

/**
 * 本题在题目中给出了很明确的提示，
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。
 * 请根据这个假设，如果反转后整数溢出那么就返回 0。
 * 所以反转部分是比较简单的，要注意的就是输入的数据是否超过int的数值范围
 * 更要注意数值反转后得到的值是否会溢出，比如题目给出的测试数据1534236469
 * 容易得到反转后是9646324351，很明显，这超出了2147483647，反转后的数据是溢出的，所以得到的结果应该为0
 * 而在溢出前的最后一次操作前，数为964632435，它是大于2147483647/10的，所以它乘10溢出了
 * 所以在乘10前检验会不会小于−2^31/10或者大于(2^31−1)/10，即可避免溢出
 * 官方题解还有对要加数的值进行了判断，但评论有另一种思路
 * 我觉得官方的代码有多余，因为int类型最大数和最小数开头的数字只能是1或2，所以如果有最后一次循环的话，pop的值一定为1或2，所以(rev == INT_MAX / 10 && pop > 7)和(rev == INT_MIN / 10 && pop < -8)判断可以省略。
 * 这也是非常有道理的
 * 确实，如果已知int类型范围的开头数字，这样还能省去判断pop值的步骤，但如果换为其他类型的还是需要像官方这样判断pop的，这样是这种题型的最优解了
 */

```
