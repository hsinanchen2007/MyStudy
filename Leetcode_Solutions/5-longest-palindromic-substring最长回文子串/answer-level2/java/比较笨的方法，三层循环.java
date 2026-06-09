### 解题思路
从末尾开始查找与之前可能会形成回文的字符串，只要有就肯定是最长的

### 代码

```java
class Solution {
    public String longestPalindrome(final String s) {
        String test = "";

        if (s == null || s.equals(""))
            return test;

        test = s.charAt(0) + "";

        for (int i = 0; i < s.length(); i++) {
            final char first = s.charAt(i);
            for (int j = s.length() - 1; j > i; j--) {
                final char second = s.charAt(j);
                if (second == first) {
                    int z = 1;
                    while (s.charAt(j - z) == s.charAt(i + z) && (j - z >= i + z)) {
                        z++;
                    }

                    if (j - z < i + z) {
                        final String test2 = s.substring(i, j + 1);
                        if (test2.length() > test.length()) {
                            test = test2;
                        }
                        break;
                    }
                }
            }
        }

        return test;
    }
}
```