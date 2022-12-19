### 解题思路
此处撰写解题思路
**1.匹配，递归=第一个字符匹配&&剩余内容匹配。**
**2.有`.`时，相等的含义：`!text.isEmpty() &&s.charAt(0)==p.charAt(0)||p.charAt(0)=='.' `**
**3.“*”的含义为：从头开始递归时，处于第二个位置，处理方式：1.text向后移动一位，pattern不变，2.跳过这个模式，直接从下一个位置开始pattern[2]**
### 代码

```java
class Solution {
    public boolean isMatch(String text, String pattern) {
        if (pattern.isEmpty()) return text.isEmpty();
        boolean first_match = (!text.isEmpty() &&
                               (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));

        if (pattern.length() >= 2 && pattern.charAt(1) == '*'){
            return (isMatch(text, pattern.substring(2)) ||
                    (first_match && isMatch(text.substring(1), pattern)));
        } else {
            return first_match && isMatch(text.substring(1), pattern.substring(1));
        }
    }
}
```