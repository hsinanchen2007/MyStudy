### 解题思路
Java的两种写法吧，方法一效率高一些

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
//        int lastWordLength = 0;
//         if (s.isEmpty() || s == null) return 0;
// //        if (!s.contains(" ")) return 0;
//         String[] a = s.split(" ");
//         if (a.length > 0) return a[a.length - 1].length();
//         return lastWordLength;
 int lastWordLength = 0;
        int i = 0;
        if (s.isEmpty()) return 0;
        s = s.trim();
        while (i < s.length()) {
            lastWordLength++;
            if (s.charAt(i++) == ' ') {
                lastWordLength = 0;
            }
        }
        return lastWordLength;
    }
}
```