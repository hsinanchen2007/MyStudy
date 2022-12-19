### 解题思路
isLetterOrDigit
equalsIgnoreCase

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        char[] chars = s.toCharArray();
        StringBuffer stringBuffer = new StringBuffer();
        for (int i = 0; i < chars.length; i++) {
            if (Character.isLetterOrDigit(chars[i])) {
                stringBuffer.append(chars[i]);
            }
        }
        return stringBuffer.toString().equalsIgnoreCase(stringBuffer.reverse().toString());
    }
}
```