### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int myAtoi(String str) {
  // 首字符必须是符号或者数字 否则返回0
        char[] chars = str.toCharArray();
        char first = ' ';
        // 找到第一个非空的字符
        int index = -1;
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] != ' ') {
                first = chars[i];
                index = i;
                break;
            }
        }
        if (first == '+' || first == '-' || Character.isDigit(first)) {
            StringBuilder builder = new StringBuilder();
            builder.append(first);
            for (int i = index + 1; i < chars.length; i++) {
                if (!Character.isDigit(chars[i])) {
                    break;
                }
                builder.append(chars[i]);
            }
            // 确保没'-' 的情况出现
            String s = builder.toString();
            if (s.length() == 1 && (s.equals("-") || s.equals("+"))) {
                return 0;
            }
            try {
                return Integer.parseInt(s);
            }catch (NumberFormatException e){
                return first == '-' ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
        } else {
            return 0;
        }
    }
}
```