```
class Solution {
    public boolean isPalindrome(String s) {
        s=s.trim().toLowerCase();
        int low = 0;
        int high = s.length()-1;
        while(low<high){
            if(!Character.isLetterOrDigit(s.charAt(low))){
                low++;
                continue;
            }
            if(!Character.isLetterOrDigit(s.charAt(high))){
                high--;
                continue;
            }
            if(s.charAt(low)!=s.charAt(high)){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
}
```
