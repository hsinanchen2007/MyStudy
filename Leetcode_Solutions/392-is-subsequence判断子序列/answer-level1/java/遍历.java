### 解题思路
遍历
### 代码

```java
class Solution {
    public  boolean isSubsequence(String s, String t) {
     if(s.length() >t.length()){
          return false;
      }
      if (s.equals(t)){
          return true;
      }
      int i=0;
      int j=0;
      while (i<s.length()){
          while (j<t.length() && s.charAt(i) != t.charAt(j)){
              j++;
          }
          if (j>=t.length()){
              return false;
          }
          j++;
          i++;
      }
      return true;
    }
    时间复杂度:O(n^2)
    空间复杂度:O(1)

   


}
```