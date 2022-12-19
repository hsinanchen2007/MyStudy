```java
class Solution {
    public static boolean isPalindrome(String s) {
        s = s.toLowerCase();
        for(int i = 0,j = s.length()-1;i<=j;i++,j--){
            while (i<s.length()-1 && !Character.isLetter(s.charAt(i)) && !Character.isDigit(s.charAt(i))){
                i++;
            }
            while (j>-1 && !Character.isLetter(s.charAt(j)) && !Character.isDigit(s.charAt(j))){
                j--;
            }
            if(i>j)
                return true;
            if(s.charAt(i) != s.charAt(j))
                return false;
        }
        return true;
    }
}
```
