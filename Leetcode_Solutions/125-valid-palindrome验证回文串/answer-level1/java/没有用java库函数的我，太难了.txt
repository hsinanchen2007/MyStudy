```
class Solution {
    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length()-1;

        while(i < j){
            while((s.charAt(i) < 48 || (s.charAt(i) > 57 && s.charAt(i) < 65) || (s.charAt(i) > 90 && s.charAt(i) < 97) || s.charAt(i) > 122) && i < j)
                i++;
            while((s.charAt(j) < 48 || (s.charAt(j) > 57 && s.charAt(j) < 65) || (s.charAt(j) > 90 && s.charAt(j) < 97) || s.charAt(j) > 122) && i < j)
                j--;

            if(i < j && (((s.charAt(i) < 65 && s.charAt(j) >= 65)||(s.charAt(i) < 65)&&(s.charAt(j) >=65)) || (s.charAt(i) != s.charAt(j) && s.charAt(i) != s.charAt(j)+32 && s.charAt(i)+32 != s.charAt(j))))
                return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
}
```
