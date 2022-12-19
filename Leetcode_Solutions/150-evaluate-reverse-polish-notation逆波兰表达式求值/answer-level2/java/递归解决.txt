### 解题思路
递归解决，代码比较简单

### 代码

```java
class Solution {
   public  int evalRPN(String[] tokens) {
        index = tokens.length - 1;
        return getPrefix(tokens);
    }

     int index;

    public  int getPrefix(String[] tokens) {
        String token = tokens[index--];
        if (token.equals("+")) {
            int prefix1 = getPrefix(tokens);
            int prefix0 = getPrefix(tokens);
            return prefix0 + prefix1;
        } else if (token.equals("-")) {
            int prefix1 = getPrefix(tokens);
            int prefix0 = getPrefix(tokens);
            return prefix0 - prefix1;
        } else if (token.equals("*")) {
            int prefix1 = getPrefix(tokens);
            int prefix0 = getPrefix(tokens);
            return prefix0 * prefix1;
        } else if (token.equals("/")) {
            int prefix1 = getPrefix(tokens);
            int prefix0 = getPrefix(tokens);
            return prefix0 / prefix1;
        } else {
            return Integer.parseInt(token);
        }
    }
}
```