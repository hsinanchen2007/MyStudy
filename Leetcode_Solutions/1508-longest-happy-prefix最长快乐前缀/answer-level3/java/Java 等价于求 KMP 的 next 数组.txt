KMP 算法中的 next 数组描述的就是字符串中前缀与后缀的最长匹配长度. `next[i] = j` 表示在 i 之前的子串的最长匹配长度为 j, 即前缀 `[0, ..., j - 1]` 与后缀 `[i - j, ..., i - 1]` 匹配, 这样求得的 `next[s.length()]` 即为快乐前缀的最长长度.

```java
class Solution {
  public String longestPrefix(String s) {
    int[] next = getNext(s);
    int n = next[s.length()];
    return s.substring(0, n);
  }

  int[] getNext(String s) {
    int[] next = new int[s.length() + 1];
    int i = 0, j = -1;
    next[0] = -1;
    while (i < s.length()) {
      if (j == -1 || s.charAt(j) == s.charAt(i))
        // 已有 [0, ..., j - 1] 与 [i - j, ..., i - 1] 匹配, 同时 s[j] == s[i]
        next[++i] = ++j;
        // 匹配长度增加 1, 查看下一个匹配位置
      else
        j = next[j];
        // 不匹配, 说明当前查看的前缀太长, 将 j 跳回到上一个可能的匹配位置
    }
    return next;
  }
}
```
