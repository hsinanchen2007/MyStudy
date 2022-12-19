### 解题思路

首先需要找到最后一个单词，之前想过从后向前遍历找到第一个不是字母的字符，就基本找到了。

但是很傻啊，那么多库函数，直接使用 trim 先，然后 lastIndexOf(" ") 就找到了，然后 substring 一下就结束了

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        int start = s.lastIndexOf(" ") + 1;
        return s.substring(start).length();
    }
}
```