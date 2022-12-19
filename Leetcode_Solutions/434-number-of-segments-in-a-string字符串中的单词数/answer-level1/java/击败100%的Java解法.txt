### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countSegments(String s) {
      if (s.isEmpty()) {
          return 0;
      }  
      int i = 0;
      int count = 0;
      while(i < s.length()) {
          while(i < s.length() && s.charAt(i) == ' ') {
              ++i;
          }
          while(i < s.length() && s.charAt(i) != ' ') {
              ++i;
          }
          ++count;
      }
      return count - (s.charAt(s.length() - 1) == ' ' ? 1 : 0);

    }
}
```