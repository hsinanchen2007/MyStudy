### 解题思路
采用HashSet的数据结构，首先获取字符串的字符数组，遍历数组，从Set中进行删除字符，如果存在，则num++，如果不存在，则将该字符add。

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        Set<Character> set = new HashSet<Character>(s.length() / 2);
        char[] charArr = s.toCharArray();
        int num = 0;
        for (char cha : charArr) {
            if (!set.remove(cha)) {
                set.add(cha);
            } else {
                num++;
            }
        }

        return set.size() != 0 ? num * 2 + 1 : num * 2;
    }
}
```