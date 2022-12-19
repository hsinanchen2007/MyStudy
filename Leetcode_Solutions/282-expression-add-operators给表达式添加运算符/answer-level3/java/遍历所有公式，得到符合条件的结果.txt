### 解题思路

就题目来看，整个两个数之间的连接符号，可以分为四种：
+，-，*，null
而这四种，根据优先级，可以分为三层：
优先级最高的为null，其次为*，最后才是+-。
Calculator的三个方法，nextConnect，nextTimes，next对应这三种优先级。
next表示，当前公式的值和下一个数字之间的连接必为+或者-，计算的公式为num1(+ or -)nums[index]
nextTimes表示，当前公式的值和下一个数字之间的连接必为*，计算的公式为num1+num2*nums[index]
nextConnect表示，当前公式的值和下一个数字之间的连接必为null，计算的公式为num1+ num2 * num3 nums[index]

### 代码

```java
import java.util.LinkedList;
import java.util.List;

public class Solution {
     public List<String> addOperators(String num, int target) {
        char[] chars = num.toCharArray();
        long[] array = new long[chars.length];
        for (int i = 0; i < array.length; i++) {
            array[i] = chars[i] - '0';
        }
        return new Calculator(target, array).execute();
    }
}


class Calculator {
    private List<String> expressions;
    private long target;
    private long[] nums;

    public Calculator(long target, long[] nums) {
        this.target = target;
        this.nums = nums;
    }

    public List<String> execute() {
        if (expressions == null) {
             expressions = new LinkedList<>();
            if (nums.length > 1) {
                long num1 = nums[0];
                String exp = String.valueOf(num1);
                next(exp, num1, 1);
                nextTimes(exp, 0, num1, 1);
                nextConnect(exp, 0, 1, num1, 1);
            }
        }
        return expressions;
    }


    private void next(String exp, long num1, int index) {
        long num2 = nums[index];
        index++;
        String nextExp = exp + "+" + num2;
        if (hasNext(nextExp, num1 + num2, index)) {
            next(nextExp, num1 + num2, index);
            nextTimes(nextExp, num1, num2, index);
            nextConnect(nextExp, num1, 1, num2, index);
        }
        nextExp = exp + "-" + num2;
        if (hasNext(nextExp, num1 - num2, index)) {
            next(nextExp, num1 - num2, index);
            nextTimes(nextExp, num1, -num2, index);
            nextConnect(nextExp, num1, 1, -num2, index);
        }
    }


    private void nextTimes(String exp, long num1, long num2, int index) {
        long num = nums[index];
        index++;
        long nextNum2 = num2 * num;
        exp = exp + "*" + num;
        if (hasNext(exp, num1 + nextNum2, index)) {
            next(exp, num1 + nextNum2, index);
            nextTimes(exp, num1, nextNum2, index);
            nextConnect(exp, num1, num2, num, index);
        }
    }

    private void nextConnect(String exp, long num1, long num2, long num3, int index) {
        if (num3 == 0) {
            return;
        }
        long num = nums[index];
        index++;
        num3 = num3 * 10 + (num3 > 0 ? num : -num);
        exp = exp + num;
        if (hasNext(exp, num1 + num2 * num3, index)) {
            next(exp, num1 + num2 * num3, index);
            nextTimes(exp, num1, num2 * num3, index);
            nextConnect(exp, num1, num2, num3, index);
        }
    }


    private boolean hasNext(String exp, long num, int index) {
        if (index == nums.length) {
            if (num == target) {
                expressions.add(exp);
            }
            return false;
        }
        return true;
    }
}
```