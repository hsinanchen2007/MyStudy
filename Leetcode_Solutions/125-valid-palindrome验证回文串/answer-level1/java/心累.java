### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        
        String str = s.toUpperCase();
        int start = 0;
        int end   =  str.length() - 1;
        while (start < end) {
            while (start < end && !isDigOrAlp(str.charAt(start))) {
                ++start;
            }
            while (start < end && !isDigOrAlp(str.charAt(end))) {
                --end;
            }
            if (str.charAt(start++) != str.charAt(end--)) {
                return false;
            }
        }
        return true;
    }

    boolean isDigOrAlp(char c)
    {
        if('0' <= c && c <= '9')
            return true;
        if('A' <= c && c<= 'Z')
            return true;
        return false;
    }
}
```