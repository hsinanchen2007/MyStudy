### 解题思路
逐步公式都可以转换为a+b*cd，next方法即是基于此

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
                next(exp, 0, 1, num1, 1);
            }
        }
        return expressions;
    }

    private void next(String exp, long num1, long num2, long num3, int index) {
        long result = num1 + num2 * num3;
        if (hasNext(exp, result, index)) {
            long num = nums[index];
            index++;
            //next +
            next(exp + "+" + num, result, 1, num, index);
            //next -
            next(exp + "-" + num, result, -1, num, index);
            //next *
            next(exp + "*" + num, num1, num2 * num3, num, index);
            //next null
            if (num3 != 0) {
                num3 = num3 * 10 + (num3 > 0 ? num : -num);
                next(exp + num, num1, num2, num3, index);
            }
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