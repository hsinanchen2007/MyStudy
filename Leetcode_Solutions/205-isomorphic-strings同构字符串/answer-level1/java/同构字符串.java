### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
       for (int i = 0; i < s.length(); i++) {
      if (s.indexOf(s.charAt(i)) != t.indexOf(t.charAt(i))) 
      return false;
  }
  return true;
    }
}
```