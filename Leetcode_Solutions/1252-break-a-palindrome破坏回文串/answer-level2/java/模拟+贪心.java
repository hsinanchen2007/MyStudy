### 解题思路
其实很好做，只要找到尽可能前面的不为a的字符将其替换为26个字母中尽可能小的那一个即可，需要注意回文的判断和全是a的情况

### 代码

```java
class Solution {
    public String breakPalindrome(String palindrome) {
        if (palindrome.equals("a")) return "";
        for (int i = 0; i < palindrome.length(); i++) {
            if (palindrome.charAt(i) == 'a' && i == palindrome.length() - 1) return palindrome.substring(0, i) + "b";
            if (palindrome.charAt(i) == 'a') continue;
            for (int j = 0; j < 26; j++) {
                StringBuilder sb = new StringBuilder(palindrome);
                sb.deleteCharAt(i);
                sb.insert(i, (char)('a' + j));
                if (!reverse(sb.toString())) return sb.toString();
            }
        }
        return "";
    }
    
    boolean reverse(String s) {
        StringBuilder sb = new StringBuilder(s);
        return s.equals(sb.reverse().toString());
    }
}
```