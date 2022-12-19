### 解题思路
利用双指针同步进行比较，遇到非法的字符直接跳过该字符即可。 其中比较字符时如果两边大小写不一致则进行一下转换后在比较。

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
      if(s.length() == 0) return true;
      int left = 0; int right = s.length() - 1;
      while(left < right) {
          if(!validateChar(s.charAt(left))) {
             left++;continue;
          }
          if(!validateChar(s.charAt(right))) {
             right--;continue;
          }
         if(!equalsIgnoreChar(s.charAt(left), s.charAt(right))) {
             return false;
         }
         left++; right--;
      }
      return equalsIgnoreChar(s.charAt(left), s.charAt(right));
    }

    private boolean validateAz(char c) {
        return (c >= 'a' && c <='z') || (c >= 'A' && c <='Z');
    }

    private boolean validateChar(char c) {
        return  validateAz(c) || (c >= '0' && c<='9');
    }

    private boolean equalsIgnoreChar(char a, char b) {
        if(a == b) return true;
        if(validateAz(a) && validateAz(b)) {
            return a > b ? a-32 == b : a == b-32;
        }
        return false;
    }
}
```