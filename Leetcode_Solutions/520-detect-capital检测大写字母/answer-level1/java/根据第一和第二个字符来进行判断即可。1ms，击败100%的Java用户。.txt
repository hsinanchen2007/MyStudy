### 解题思路
这里的约束条件其实通过第一和第二字符来确定。
第一个字符是小写，则整个单词都必须是小写。
第一个字符是大写，而第二个字符是小写，则后续所有字符也必须小写。
第一个字符是大写，而第二个字符是大写，则后续所有字符也必须大写。
否则上述规则，就是true，否则就是false。


### 代码

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        boolean ans = true;
        char firstChar = word.charAt(0);
        if ((firstChar >= 'A') && (firstChar <= 'Z')) {
            if (word.length() >= 2) {
                char secondChar = word.charAt(1);
                if ((secondChar >= 'A') && (secondChar <= 'Z')) {
                    for (int i = 2; i < word.length(); i++) {
                        char currChar = word.charAt(i);
                        if (!((currChar >= 'A') && (currChar <= 'Z'))) {
                            ans = false;
                            break;
                        };
                    };
                } else {
                    for (int i = 2; i < word.length(); i++) {
                        char currChar = word.charAt(i);
                        if ((currChar >= 'A') && (currChar <= 'Z')) {
                            ans = false;
                            break;
                        };
                    };
                }
            };
        } else {
            for (int i = 1; i < word.length(); i++) {
                char currChar = word.charAt(i);
                if ((currChar >= 'A') && (currChar <= 'Z')) {
                    ans = false;
                    break;
                };
            };
        };
        return ans;
    }
}
```