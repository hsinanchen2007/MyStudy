边界和细节比较多的一道题

除了常规的从前往后扫描处理，比较好的思路有官方题解中的使用**状态机**，或者使用**正则表达式进行捕获**后再直接转int

### 常规从前往后扫描处理
最常规的处理方式，从前往后处理并累积计算。
时间复杂度 `O(n)`，空间复杂度 `O(1)`
```java
private static class SolutionV2020 {
    public int myAtoi(String str) {
        if (null == str) {
            return 0;
        }
        // 去掉前后空白
        str = str.trim();
        if (str.length() == 0) {
            return 0;
        }
        char[] chars = str.toCharArray();
        int sign = 1;
        int start = 0;
        // 处理开头的符号位
        if (chars[0] == '-' || chars[0] == '+') {
            start = 1;
            if (chars[0] == '-') {
                sign = -1;
            }
        } else if (!(chars[0] >= '0' && chars[0] <= '9')) {
            return 0;
        }
        long res = 0;
        for (int i = start; i < chars.length; i++) {
            if (chars[i] >= '0' && chars[i] <= '9') {
                long temp = res * 10 + chars[i] - '0';
                if (temp * sign > Integer.MAX_VALUE) {
                    return Integer.MAX_VALUE;
                } else if (temp * sign < Integer.MIN_VALUE) {
                    return Integer.MIN_VALUE;
                }
                res = (int)temp;
            } else {
                break;
            }
        }
        return (int)res * sign;
    }
}
```

### Java正则表达式解决字符串转整型atoi
不推荐这种解法，很慢，比直接从前往后扫描处理慢一个数量级。
时间复杂度也不好分析，但作为复习Java正则表达式，还是可以写一下的，当练手了。
```java
public int myAtoi2(String str) {
    Pattern pattern = Pattern.compile("( *)([+-]?\\d+).*");
    Matcher matcher = pattern.matcher(str);
    // 先用 matches() 对整个串进行完全匹配
    if (!matcher.matches()) {
        return 0;
    }
    // 重置匹配器后，使用 find() 进行部分匹配，其中的第2个捕获组就是合法整数对应的字符串
    matcher.reset();
    if (matcher.find()) {
        String validIntStr = matcher.group(2);
        try {
            return Integer.parseInt(validIntStr);
        } catch (NumberFormatException e) {
            return validIntStr.startsWith("-") ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        }
    }
    return 0;
}
```

