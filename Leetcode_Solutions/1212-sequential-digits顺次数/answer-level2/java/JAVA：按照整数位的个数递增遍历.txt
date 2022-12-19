### 按照某位大神的指点开始写题解，处女解谢谢

1. 最外层`m`循环控制结果的10进制位数，从2到9
    1. 也就是从`10`到`123456789`
    2. 如果`high`小于本位的最小数值，即`10 ^ (m - 1)`，提前退出
2. 内层循环`i`控制最高位的取值
3. 最内层`while`负责生成下一个数
    1. 用`i`作为最高位，然后逐次`+1`作为下一位的值
    2. 保证生成的结果是`m`位
4. 将落在区间内的结果记录

### 感觉还可以更简洁，有灵感再优化~

```
class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> result = new LinkedList();

        for (int m = 2; m <= 9 && Math.pow(10, m - 1) < high; m++) {
            for (int i = 1; i <= 8; i++) {
                int value = i;
                int j = i;
                while (++j - i < m && j < 10) {
                    value = value * 10 + j;
                }
                if (j - i == m && value >= low && value <= high) {
                    result.add(value);
                } else if (value > high) {
                    break;
                }
            }
        }
        
        return result;
    }
}
```

### 还是这种思路的另外一种解法

1. 提前将符合规则的数字字符串准备好
2. 依次按位数窗口截取字符串中的值，即为满足条件的数值
3. 如果该数值落在区间内，记录结果

```
class Solution {
    private static final String digits = "123456789";

    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> result = new LinkedList();

        for (int i = 2; i <= 9; i++) {
            for (int m = 0, n = m + i; n <= 9; m++, n++) {
                int value = Integer.valueOf(digits.substring(m, n));
                if (value >= low && value <= high) {
                    result.add(value);
                } else if (value > high) {
                    break;
                }
            }
        }

        return result;
    }
}
```
