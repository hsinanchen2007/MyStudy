### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean validPalindrome(String s) {
        for (int i = 0, j = s.length()-1; i <= j; i++,j--) {
            if (s.charAt(i) != s.charAt(j)) {
                return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
            }
        }
        return true;
    }
    
    public boolean isPalindrome(String s, int start, int end) {
        int left = start;
        int right = end;
        while (left<= right) {
            if (s.charAt(left++) != s.charAt(right--)) {
                return false;
            }
        }
        return true;
    }
    
}
```