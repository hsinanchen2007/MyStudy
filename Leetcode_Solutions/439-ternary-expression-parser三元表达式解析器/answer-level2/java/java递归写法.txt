### 解题思路
从后往前，遇到三元表达式就求解并生成一个新的表达式，多次替换后就只一个三元表达式，求值即可

### 代码

```java
class Solution {
    public String parseTernary(String expression) {
        if (expression == null || expression.length() == 1) {
            return expression;
        }
        for (int i = expression.length() - 1; i >= 0; i -= 2) {
            char[] words = expression.toCharArray();
            if (words[i - 3] == '?' && words[i - 1] == ':')
                return parseTernary(expression.substring(0, i - 4)
                        + (words[i - 4] == 'T' ? words[i - 2] : words[i - 0])
                        + expression.substring(i + 1));
        }
        return "";
    }
}
```