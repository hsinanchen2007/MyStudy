
先简单分析一下题意：给定一个字符串，忽略开头空格，忽略 ‘+-’,第一位有效字符是数字，往后取出连续数字字符，遇到非数字字符中断操作；否则结果返回0；

下面为具体解题思路：
1. 去除开头空格。
2. 判断‘+-’符号。
3. 如果是带+-符号的数字，并且判断字符长度。如果只有一个符号位，直接返回0，否则截取符号位下一位开始的字符串。
4. 判断完‘+-’符号后，开始判断第一位有效字符是否是数字。
5. 去除开头多余的0。
6. 遍历剩余字符，找出连续的数字字符返回。

执行结果如下：
    执行用时：3ms
    内存消耗：39.7m

总体来说比较耗时，内存消耗较大。
各位大牛请提优化建议，尽情鞭笞我！

代码如下：

```
 public int myAtoi(String str) {
        //1、去除开头空字符串
        String newStr = str.trim();
        if (newStr.isEmpty()) {
            return 0;
        }

        //2、判断符号
        int sign = 0;//1 代表+，-1 代表 -，0 代表没有符号
        if (newStr.charAt(0) == '+') {
            sign = 1;
        } else if (newStr.charAt(0) == '-') {
            sign = -1;
        }

        //3、如果是带+-符号的数字，并且判断字符长度。如果只有一个符号位，直接返回0，否则截取符号位下一位开始的字符串。
        if (sign != 0 && newStr.length() > 1) {
            newStr = newStr.substring(1, newStr.length());
        }

        //4、判断完‘+-’符号后，开始判断第一位有效字符是否是数字。
        if (newStr.charAt(0) >= '0' && newStr.charAt(0) <= '9') {
            //5、去除开头多余的0
            newStr = trim0(newStr);

            Log.e("TAG", " trim0 str =  " + newStr);
            //6、遍历剩余字符，找出连续的数字字符返回。
            long result = 0L;

            int start = 0;
            int len = newStr.length();
            while ((start < len) && (newStr.charAt(start) >= '0' && newStr.charAt(start) <= '9')) {
                result = result * 10 + newStr.charAt(start) - '0';
                if (result > Integer.MAX_VALUE) {
                    result = Integer.MAX_VALUE;

                    return (int) (sign == -1 ? (result * sign - 1) : result);
                }
                start++;
            }

            return (int) (sign == -1 ? (result * sign) : result);


        }
        return 0;

    }

    //参考String.trim() 方法
    private String trim0(String str) {
        int len = str.length();
        int start = 0;
        while ((start < len) && (str.charAt(start) == '0')) {
            start++;
        }

        return start > 0 ? str.substring(start, len) : str;

    }
```
