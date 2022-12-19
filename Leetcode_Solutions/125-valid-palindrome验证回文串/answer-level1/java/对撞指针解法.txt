### 解题思路
对撞指针左右逼近

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            boolean bl = Character.isLetterOrDigit(s.charAt(l));
            boolean br = Character.isLetterOrDigit(s.charAt(r));
            if (bl && br) {
                if (Character.toLowerCase(s.charAt(l)) != Character.toLowerCase(s.charAt(r))) {
                    return false;
                }
                l++;
                r--;
            }
            if (!bl) l++;
            if (!br) r--;
        }
        return true;
    }
}
```