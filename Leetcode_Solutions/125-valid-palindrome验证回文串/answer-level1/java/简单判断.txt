```
class Solution {
    public boolean isPalindrome(String s) {
        String ss = s.toLowerCase();
        StringBuilder sb = new StringBuilder();
        int i;
        for(i = 0;i < ss.length();i++){
            if((ss.charAt(i) > 96 && ss.charAt(i) < 123) || (ss.charAt(i) > 47 && ss.charAt(i) < 58))
                sb.append(ss.charAt(i));
        }
        String s2 = sb.toString();
        String s1 = sb.reverse().toString();
        if(s1.equals(s2))
            return true;
        else
            return false;
    }
}
```
