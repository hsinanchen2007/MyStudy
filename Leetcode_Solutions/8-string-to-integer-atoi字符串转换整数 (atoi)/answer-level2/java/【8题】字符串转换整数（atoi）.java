**方法一：遍历字符串**
思路：
基本思想就是判断字符串每个字符是否是编码表 0~9 （包含边界）直间的字符。

然后需要考虑的就是题目要求：
(1) 从第一个非空字符开始算起。
(2) 如果第一个非空字符为正号或者负号，则记录为转换结果的符号。
(3) 转换内容只包括开始的非空整数串，如果开始不是符号或者数字串，则记录为0。
(4) 转换后为整数类型，也就是要求转换后数字范围在 int 类型范围内，超过则记录为边界值。
*** 需要注意的两点就是符号记录和int类型溢出的处理。

最后根据要求写操作流程：
(1) 遍历字符串，跳过开头的空格部分。
(2) 判断除空格以外第一个字符，记录正负。
(3) 截取合法整数串判断是否越界Integer并添加符号。
```
public class Solution {
    public int myAtoi(String str) {
        int len = str.length();
        // 跳过字符串开始空格
        int index = 0;
        while (index < len) {
            if (str.charAt(index) != ' ') {
                break;
            }
            index++;
        }
        if (index == len) {
            return 0;
        }
        // 第 1 个字符如果是符号，判断合法性，并记录正负
        int sign = 1;
        char firstChar = str.charAt(index);
        if (firstChar == '+') {
            index++;
        } else if (firstChar == '-') {
            index++;
            sign = -1;
        }
        int res = 0;
        while (index < len) {
            char currChar = str.charAt(index);
            // 判断是否为数字字符
            if (currChar > '9' || currChar < '0') {
                break;
            }
            // 提前判断拼接当前数字字符之后是否会int类型越界
            if (res > Integer.MAX_VALUE / 10 || (res == Integer.MAX_VALUE / 10 && (currChar - '0') > Integer.MAX_VALUE % 10)) {
                return Integer.MAX_VALUE;
            }
            if (res < Integer.MIN_VALUE / 10 || (res == Integer.MIN_VALUE / 10 && (currChar - '0') > -(Integer.MIN_VALUE % 10))) {
                return Integer.MIN_VALUE;
            }
            // 每一步都把符号位乘进去
            res = res * 10 + sign * (currChar - '0');
            index++;
        }
        return res;
    }
}
```
