### 法一
用一个辅助数组，同时遍历的时候记录有多少个相同字符.

### 代码

```java
class Solution {
    public String compressString(String s) {
        if (0 == s.length()) {
            return s;
        }
        StringBuilder result = new StringBuilder(s.charAt(0) + "");
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                count++;
            } else {
                result.append(count);
                result.append(s.charAt(i));
                count = 1;
            }
        }
        result.append(count);

        return result.toString().length() >= s.length() ? s : result.toString();
    }
}
```
### 法二
思路同法一，但是增加了变量chNew,chOld，这样可以减少随机访问次数，提升效率。

```java
class Solution {
    public String compressString(String s) {
        if (0 == s.length()) {
            return s;
        }
        
        char[] chars = s.toCharArray();
        char chOld = chars[0], chNew = chOld;//提升效率
        StringBuilder result = new StringBuilder();
        result.append(chNew);
        int length = chars.length;
        int count = 1;
        
        for (int i = 1; i < length; i++) {
            chNew = chars[i];
            if (chOld != chNew) {
                result.append(count);
                result.append(chNew);
                count = 1;
                chOld = chNew;
                continue;
            }
            count++;
        }
        result.append(count);

        return result.toString().length() >= length ? s : result.toString();
    }
}
```
