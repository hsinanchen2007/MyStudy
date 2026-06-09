### 解题思路
解题思路见注释。
1. 先去除首尾空格，再检查字符长度是否为0，否则下面判断正负的时候，直接额访问index为0的位置会抛空指针异常
2. 判断正负数
3. 找到连续数字之后的第一个非数字字符下标（第一个字符可以为+/-）
4. 进行连续数字的数字转换（注意正负数的溢出判断，本题目为了通过题目在正数溢出时返回最大值；负数溢出时返回最小值）
5. 针对溢出时候的处理，可以和面试官确认！！！

### 代码

```java
class Solution {
    public int strToInt(String str) {
        str = str.trim(); // 去除首尾的空格
        if (str == null || str.length() == 0) {
            return 0;
        }
        // Note：先去除空格，再检查字符长度是否为0，否则下面判断正负的时候，直接额访问index为0的位置会抛空指针异常

        System.out.println(str);
        boolean flag = true; // 是否为正数
        if (str.charAt(0) == '-') {
            flag = false;
        }

        int i = 0;
        while (i < str.length()) {
            if (i == 0 && (str.charAt(i) == '-' || str.charAt(i) == '+')) {
                i++;
                continue;
            }

            if (str.charAt(i) > '9' || str.charAt(i) < '0') {
                break;
            }
            i++;
        } // 找到第一个非数字的字符，然后后续处理只处理前面连续数字即可

        int count = 0;
        int val = 0;
        for (int j = i - 1; j >= 0; j--) {
            char c = str.charAt(j);
            System.out.println(c);
            if (c == '-' || c == '+') {
                if (j == 0) {
                    return val;
                }
                return 0;
            }
            if (c >= '0' && c <= '9') {
                int num = c - '0';
                num *= Math.pow(10, count);
                if (flag) {
                    if ((Integer.MAX_VALUE - val) < num) {
                        return Integer.MAX_VALUE; // 检测这里要求正数溢出时返回最大值
                    }
                    val += num;
                    count++;
                } else {
                    if (val != 0 && (Math.abs(Integer.MIN_VALUE - val)) < num) {
                        return Integer.MIN_VALUE; // 检测这里要求负数溢出时返回最小值
                    }
                    val -= num;
                    count++;
                }
            } else {
               return val;
            }
        }

        return val;
    }
}
```