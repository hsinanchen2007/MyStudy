### 解题思路
就是把乘法的规则实现一遍就完事了
如果投机的话，可以把999999999 * 999999999 是可以直接求的
当然我们不会面向测试用例编程，对吧。

### 代码

```java
class Solution {
    // 解题思路
    // 乘法就按照小学思路逐个解题就好
    // 用到巨大数字乘以单数
    // 用到巨大两个数字相加
    // 记得进位就行
    public String multiply(String num1, String num2) {
        if ("0".equals(num1) || "0".equals(num2)) {
            return "0";
        }
        // 快速优化方案 - 投机取巧的方法，可以在实战中打开，能节省很多时间
        // 999999999 * 999999999 是可以直接求的，不会溢出
        // 小于long的可以直接用乘法，经过实验，两个数字位数之和小于等于18位的，可以直接计算
//        if (num1.length() + num2.length() <= 18) {
//            return "" + Long.parseLong(num1) * Long.parseLong(num2);
//        }

        // 被乘数（左侧）
        String multiplicand = null;
        // 乘数（右侧），乘数就是倍数
        String multiplier = null;
        // 选长度大的作为被乘数，这样可以减少循环
        if (num1.length() > num2.length()) {
            multiplicand = num1;
            multiplier = num2;
        } else {
            multiplicand = num2;
            multiplier = num1;
        }
        String result = "0";
        // 这是10的幂
        // 从0开始计算
        int tenPower = 0;
        // 从被乘数最后一位倒着乘
        for (int i = multiplier.length(); i > 0; i--) {
            String t = this.longStringMultiplySingleNumber(multiplicand, multiplier.substring(i-1, i));
            result = this.longStringAdd(this.longStringMultiply10Times(t, tenPower), result);
            tenPower++;
        }
        return result;
    }


    // 一个巨大数乘以一个单数
    public String longStringMultiplySingleNumber(String huge, String a) {
        int overflow = 0;
        StringBuilder result = new StringBuilder();
        int ia = Integer.parseInt(a);
        for (int i = huge.length(); i > 0; i--) {
            int c = Integer.parseInt(huge.substring(i - 1, i));
            int t = c * ia + overflow;
            if (t >= 10) {
                overflow = t / 10;
                t = t % 10;
            } else {
                overflow = 0;
            }
            result.insert(0, t);
        }
        if (overflow > 0) {
            result.insert(0, overflow);
        }
        return result.toString();
    }

    // 一个巨大数乘以10的幂
    // 10^0 , 10^1,...
    public String longStringMultiply10Times(String huge, int times) {
        StringBuilder sb = new StringBuilder(huge);
        for (int i = 0; i < times; i++) {
            sb.append("0");
        }
        return sb.toString();
    }

    // 两个大长数字串相加
    public String longStringAdd(String num1, String num2) {
        // 补齐0，让两个字符串相等
        int diff = Math.abs(num1.length() - num2.length());
        StringBuilder sb = new StringBuilder();
        int i = 0;
        while (i < diff) {
            sb.append("0");
            i++;
        }
        if (num1.length() > num2.length()) {
            // 补齐num2
            num2 = sb.append(num2).toString();
        } else {
            num1 = sb.append(num1).toString();
        }
        // 开始逐位计算加法
        StringBuilder result = new StringBuilder();
        int overflow = 0;
        for (i = num1.length(); i > 0; i--) {
            int n1 = Integer.parseInt(num1.substring(i - 1, i));
            int n2 = Integer.parseInt(num2.substring(i - 1, i));
            int t = n1 + n2 + overflow;
            if (t >= 10) {
                t -= 10;
                overflow = 1;
            } else {
                overflow = 0;
            }
            result.insert(0, t);
        }
        if (overflow > 0) {
            result.insert(0, overflow);
        }
        return result.toString();
    }
}
```