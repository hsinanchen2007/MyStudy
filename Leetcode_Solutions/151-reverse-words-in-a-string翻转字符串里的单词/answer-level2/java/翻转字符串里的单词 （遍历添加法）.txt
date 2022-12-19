- 先处理字符串，将首尾空格都删除；
1. 倒序遍历字符串，当第一次遇到空格时，添加`s[i + 1: j]`（即添加一个完整单词）；
2. 然后，将直至下一个单词中间的空格跳过，并记录下一个单词尾部`j`；
3. 继续遍历，直至下一次遇到第一个空格，回到`1.`步骤；
- 由于首部没有空格，因此最后需要将第一个单词加入，再return。
- python可一行实现。

```python []
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        res = ""
        i, j = len(s) - 1, len(s)
        while i > 0:
            if s[i] == ' ':
                res += s[i + 1: j] + ' '
                while s[i] == ' ': i -= 1
                j = i + 1
            i -= 1
        return res + s[:j]
```
```python []
    def reverseWords1(self, s: str) -> str:
        return " ".join(s.split()[::-1])
```
```java []
class Solution {
    public String reverseWords(String s) {
        StringBuffer res = new StringBuffer();
        s = s.trim(); // delete leading or trailing spaces.
        int i = s.length() - 1, j = s.length();
        while (i > 0) {
            if (s.charAt(i) == ' ') {
                res.append(s.substring(i + 1, j));
                res.append(' ');
                while (s.charAt(i) == ' ') i--; // ignore extra spaces between words.
                j = i + 1;
            }
            i--;
        }
        return res.append(s.substring(0, j)).toString();
    }
}
```