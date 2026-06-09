### 解题思路

思路一：碰到C则调整数组长度，下标，把C之后的每个元素往前移动两位，计算。O(N^2)

思路二：用栈，喷到C则栈顶元素出栈，碰到其他字符则计算后入栈，之后把栈中的元素相加即可。O(N)

### 代码

```java
class Solution {
    public int calPoints(String[] ops) {
        if (ops == null) return 0;
        int sum = 0;
        int length = ops.length;
        for (int i = 0; i < length; i++) {
            switch (ops[i]) {
                case "C":
                    sum -= Integer.parseInt(ops[i - 1]);
                    for (int j = i - 1; j < length - 2; j++) {
                        ops[j] = ops[j + 2];
                    }
                    i = Math.max(i - 2, -1);
                    length = Math.max(length - 2, 0);
                    break;
                case "D": {
                    int num = Integer.parseInt(ops[i - 1]) * 2;
                    sum += num;
                    ops[i] = num + "";
                    break;
                }
                case "+":
                    int num = Integer.parseInt(ops[i - 1]) + Integer.parseInt(ops[i - 2]);
                    sum += num;
                    ops[i] = num + "";
                    break;
                default:
                    sum += Integer.parseInt(ops[i]);
                    break;
            }
        }

        return sum;
    }
}
```