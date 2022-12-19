### 解题思路
1.是否包含" ",不包含则直接返回长度
2.如果结尾为" ",去除首位空串
3.正常截取最后一个" "后的字符，返回长度

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        String mark = " ";
        if (!s.contains(mark)) return s.length();
        if (s.endsWith(mark)) {
            s = s.trim();
        }
        return s.substring(s.lastIndexOf(mark) + 1).length();
    }
}
```