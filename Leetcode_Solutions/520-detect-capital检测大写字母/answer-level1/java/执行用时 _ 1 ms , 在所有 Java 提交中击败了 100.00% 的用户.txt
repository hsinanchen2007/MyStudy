### 解题思路
不完全执行循环，判断所有错误情况。

### 代码

```java
class Solution {

/**
    * 当前循环字符前一位的判断
    * @param word
    * @return
    */
public boolean detectCapitalUse(String word) {
    for (int i = 1; i < word.length(); i++) {
        if (word.charAt(i) - 'A' <= 25) { // 当前字母大写情况
            if (word.charAt(i-1) - 'A' > 25) {
                return false;
            }
        } else { // 当前字母小写情况
            if (i > 1 && word.charAt(i-1) - 'A' <= 25) {
                return false;
            }
        }
    }
    return true;
}
```