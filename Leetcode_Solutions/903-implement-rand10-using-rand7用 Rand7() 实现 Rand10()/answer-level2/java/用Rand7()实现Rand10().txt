>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 舍弃不在范围内的数字

假设第一个rand7()得到的值是num1，第二个rand7()得到的值是num2，那么num3 = (num1 - 1) * 7 + num2，num3的取值范围是[1, 49]。

对于[1, 40]内的num3，将其映射至[1, 10]。

对于[41, 49]范围内的num3，将其映射至[1, 9]，相当于rand9()。

继续第三次rand7()得到的值是num4，那么num5 = (num4 - 1) * 7 + num3，num5的取值范围是[1, 51]。

对于[1, 50]内的num5，将其映射至[1, 50]。

对于51，可以将其映射至1，此时与rand7()再配合得到的还是rand7()，相当于重新开始一轮循环。

执行用时：6ms，击败92.77%。消耗内存：47.5MB，击败5.64%。

```java
public class Solution extends SolBase {
    public int rand10() {
        while (true) {
            //num1在[1, 7]范围内，num2在[1, 7]范围内，num3在[1, 49]范围内
            int num1 = rand7(), num2 = rand7(), num3 = (num1 - 1) * 7 + num2;
            if (num3 >= 1 && num3 <= 40) {
                return 1 + (num3 - 1) % 10;
            }
            num3 -= 40;
            //此时num3在[1, 9]范围内，num4在[1, 7]范围内，num5在[1, 51]范围内
            int num4 = rand7(), num5 = (num4 - 1) * 7 + num3;
            if (num5 >= 1 && num5 <= 50) {
                return 1 + (num5 - 1) % 10;
            }
        }
    }
}
```