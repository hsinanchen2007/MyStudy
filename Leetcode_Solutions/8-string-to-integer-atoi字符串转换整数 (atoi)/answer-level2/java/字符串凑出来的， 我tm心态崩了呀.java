### 解题思路
错了10次以上， 所有测试用例拼起来的

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        int ln;
		if ((ln = str.length()) == 0) return 0;
        str = str.trim();
        if ((ln = str.length()) == 0) return 0;
        char fc = str.charAt(0);
        if (fc != '-' && fc != '+' && (fc < 48 || fc > 57)) return 0;
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < ln; ++i) {
            int cln = builder.length();
            char c = str.charAt(i);
            // 如果0后面的数字不是数字，那么返回0
            if (c == 48 && i < ln - 1 && (str.charAt(i + 1) < 48 || str.charAt(i + 1) > 57)) {
                builder.append(0);
                break;
            }
            // 如果已经有过数字，那么后面的字符只要不是数字跳出循环
            if (cln != 0 && (c < 48 || c > 57)) break;     
            // 当前builder为空，或者有一个符号位
            if (cln == 0 || (cln == 1 && (builder.indexOf("-") >=0 || builder.indexOf("+") >= 0)))
                if (c == 48)    // 0字符跳过
                    continue;
            // 符号 或者数字都可以拼接
            if (c == '-' || c == '+' || (c > 47 && c < 58))
                builder.append(c);  
        }
        int idx;
        // 如果有+号，把它剔除掉
        if ((idx = builder.indexOf("+")) >= 0) builder.deleteCharAt(idx);
        int bln = builder.length();
        // 在11位以内
        if (bln > 0 && bln < 12) {
            char bfc = builder.charAt(0);
			if (bfc != '-') {
				long rs = Long.valueOf(builder.toString());
				return rs > Integer.MAX_VALUE ? Integer.MAX_VALUE : (int)rs;
			} else if (bln > 1) {
				long rs = Long.valueOf(builder.deleteCharAt(0).toString());
				return rs > Integer.MAX_VALUE ? Integer.MIN_VALUE : -1 * (int) rs;
			}
        } else if (bln > 11) {  // 大整数
            return builder.indexOf("-") >= 0 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        }
        return 0;
    }
}
```