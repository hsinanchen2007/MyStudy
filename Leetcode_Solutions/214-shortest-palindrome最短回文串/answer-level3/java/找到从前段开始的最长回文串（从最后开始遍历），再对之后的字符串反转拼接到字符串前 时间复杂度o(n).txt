```
class Solution {
    public String shortestPalindrome(String s) {
        int i = 0;
        for(i = s.length()-1; i>=0; i--) {
            if(isHuiWen(s.substring(0,i+1)))
                break;
        }
        StringBuilder sb = new StringBuilder(s.substring(i+1,s.length()));
        return sb.reverse().toString()+s;
    }
    private boolean isHuiWen(String s) {
        if(s.length()==1)
            return true;
        int length = s.length();
        if(length % 2 == 0) {
            int right = length/2;
            int left = right-1;
            while(left>=0) {
                if(s.charAt(left)!=s.charAt(right))
                    return false;
                left--;
                right++;
            }
        }
        else {
            int left = length/2-1;
            int right = length/2+1;
            while(left>=0) {
                if(s.charAt(left)!=s.charAt(right))
                    return false;
                left--;
                right++;
            }
        }
        return true;
    }
}
```
