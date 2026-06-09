### 解题思路
StringBuilder类型构建一个字符栈，通过遍历压栈出栈操作，检查字符串是否满足条件。

### 代码

```java
class Solution {
    public int getType(char ch) {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                return -1;
            case ')':
            case ']':
            case '}':
                return 1;
            default:
                return 0;
        }
    }

    public char getLeft(char ch) {
        switch (ch) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
            default:
                return 0;
        }
    }

    public boolean isValid(String s) {
        StringBuilder StrStack = new StringBuilder("");

        for (char ch : s.toCharArray()) {
            int type = getType(ch);
            if (type == -1) {
                // 压栈
                StrStack.append(ch);
            } else if (type == 1) {
                // 出栈
                int strLen = StrStack.length();
                if ((strLen > 0) && (StrStack.charAt(strLen - 1) == getLeft(ch))) {
                    StrStack.setLength(strLen - 1);
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        if (StrStack.length() != 0) {
            return false;
        }

        return true;
    }
}
```